/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:35:35 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:47:50 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static void	timer_init(t_data *data, t_timeval **timer, t_player *player)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
	gui_broadcast(data, gui_pex, player);
}

static int	push(t_data *data, t_player *pusher, t_player *target)
{
	int		dir;

	if (pusher->o == N)
	{
		target->y = mod(target->y - 1, data->y);
		dir = 5;
	}
	else if (pusher->o == S)
	{
		target->y = mod(target->y + 1, data->y);
		dir = 1;
	}
	else if (pusher->o == W)
	{
		target->x = mod(target->x - 1, data->x);
		dir = 7;
	}
	else if (pusher->o == E)
	{
		target->x = mod(target->x + 1, data->x);
		dir = 3;
	}
	dprintf(target->cs, "deplacement %d\n", direction(dir, target));
	gui_broadcast(data, gui_ppo, target);
	return (1);
}

static int	find(t_data *data, t_player *player)
{
	t_tlist		*team;
	t_plist		*list;
	int			count;

	count = 0;
	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			if (list->player != player
					&& list->player->x == player->x
					&& list->player->y == player->y)
				count += push(data, player, list->player);
			list = list->next;
		}
		team = team->next;
	}
	return (count);
}

void		ccmd_push(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;

	(void)cmd;
	player = &data->fds[cs].player;
	if (!(*t))
		timer_init(data, t, player);
	else
	{
		if (find(data, player))
			dprintf(cs, "ok\n");
		else
			dprintf(cs, "ko\n");
	}
}
