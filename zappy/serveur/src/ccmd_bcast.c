/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_bcast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:36:27 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 16:34:58 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int			direction(int dir, t_player *target)
{
	if (dir && target->o == E)
		return ((dir + 1) % 8 + 1);
	if (dir && target->o == S)
		return ((dir + 3) % 8 + 1);
	if (dir && target->o == W)
		return ((dir + 5) % 8 + 1);
	return (dir);
}

static int	check_dir(int x, int y, t_player *target)
{
	if (!x && y < 0)
		return (direction(1, target));
	if (x < 0 && y < 0)
		return (direction(2, target));
	if (x < 0 && !y)
		return (direction(3, target));
	if (x < 0 && y > 0)
		return (direction(4, target));
	if (!x && y > 0)
		return (direction(5, target));
	if (x > 0 && y > 0)
		return (direction(6, target));
	if (x > 0 && !y)
		return (direction(7, target));
	if (x > 0 && y < 0)
		return (direction(8, target));
	return (0);
}

static void	bcast(t_data *data, t_player *origin, t_player *target)
{
	int		dir;
	int		x;
	int		y;

	x = origin->x - target->x;
	y = origin->y - target->y;
	if (x > data->x / 2)
		x -= data->x;
	else if (x < 0 && abs(x) > data->x / 2)
		x += data->x;
	if (y > data->y / 2)
		y -= data->y;
	else if (y < 0 && abs(y) > data->y / 2)
		y += data->y;
	dir = check_dir(x, y, target);
	dprintf(target->cs, "message %d,%s\n", dir, origin->msg);
}

static void	timer_init(t_data *data, t_timeval **timer)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, BCAST_T);
}

void		ccmd_bcast(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_tlist		*team;
	t_plist		*plist;
	t_player	*player;

	player = &data->fds[cs].player;
	if (!(*t))
		timer_init(data, t);
	else
	{
		player->msg = split_join(cmd + 1);
		gui_broadcast(data, gui_pbc, player);
		team = data->teams;
		while (team)
		{
			plist = team->list;
			while (plist)
			{
				if (plist->player != player)
					bcast(data, player, plist->player);
				plist = plist->next;
			}
			team = team->next;
		}
		dprintf(cs, "ok\n");
	}
}
