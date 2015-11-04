/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_take.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:33:58 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:48:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static int	get_index(char **cmd)
{
	if (!cmd[1])
		return (-1);
	else if (!strcmp("food", cmd[1]))
		return (0);
	else if (!strcmp("linemate", cmd[1]))
		return (1);
	else if (!strcmp("deraumere", cmd[1]))
		return (2);
	else if (!strcmp("sibur", cmd[1]))
		return (3);
	else if (!strcmp("mendiane", cmd[1]))
		return (4);
	else if (!strcmp("phiras", cmd[1]))
		return (5);
	else if (!strcmp("thystame", cmd[1]))
		return (6);
	return (-1);
}

static int	*get_pitem(t_player *player)
{
	if (player->get == 0)
		return (&player->food);
	if (player->get == 1)
		return (&player->linemate);
	if (player->get == 2)
		return (&player->deraumere);
	if (player->get == 3)
		return (&player->sibur);
	if (player->get == 4)
		return (&player->mendiane);
	if (player->get == 5)
		return (&player->phiras);
	if (player->get == 6)
		return (&player->thystame);
	else
		return (NULL);
}

static int	*get_sitem(t_square *square, int i)
{
	if (i == 0)
		return (&square->food);
	if (i == 1)
		return (&square->linemate);
	if (i == 2)
		return (&square->deraumere);
	if (i == 3)
		return (&square->sibur);
	if (i == 4)
		return (&square->mendiane);
	if (i == 5)
		return (&square->phiras);
	if (i == 6)
		return (&square->thystame);
	else
		return (NULL);
}

static void	timer_init(t_data *data, t_timeval **timer, t_player *player)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
	gui_broadcast(data, gui_pgt, player);
}

void		ccmd_take(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	t_square	*square;
	int			*p_item;
	int			*s_item;

	player = &data->fds[cs].player;
	player->get = get_index(cmd);
	if (!(*t))
		timer_init(data, t, player);
	else
	{
		square = &data->map[player->x][player->y];
		p_item = get_pitem(player);
		s_item = get_sitem(square, player->get);
		if (player->get == -1 || *s_item == 0)
			dprintf(cs, "ko\n");
		else
		{
			*s_item -= 1;
			*p_item += 1;
			dprintf(cs, "ok\n");
		}
		gui_broadcast(data, gui_pin, player);
		gui_broadcast(data, gui_bct, get_square(data, player->x, player->y));
	}
}
