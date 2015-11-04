/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_food.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:09:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:47:51 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static void	final_drop(t_data *data, t_player *player)
{
	t_square	*square;

	square = get_square(data, player->x, player->y);
	while (player->food--)
		square->food++;
	while (player->linemate--)
		square->linemate++;
	while (player->deraumere--)
		square->deraumere++;
	while (player->sibur--)
		square->sibur++;
	while (player->mendiane--)
		square->mendiane++;
	while (player->phiras--)
		square->phiras++;
	while (player->thystame--)
		square->thystame++;
	gui_broadcast(data, gui_bct, square);
}

void		player_death(t_data *data, t_player *player)
{
	t_tlist		*team;

	dprintf(player->cs, "mort\n");
	gui_broadcast(data, gui_pdi, player);
	final_drop(data, player);
	team = data->teams;
	while (team && strcmp(team->name, player->team))
		team = team->next;
	player_del(&team->list, player);
	close(player->cs);
	clean_fd(data->fds + player->cs);
}

static void	check_player(t_data *data, t_player *player, t_timeval *now)
{
	t_timeval	step;

	step = time_add(data, &player->food_t, FOOD_T);
	if (time_diff(&step, now) >= 0)
	{
		player->food--;
		player->food_t = step;
	}
	if (!player->food)
		player_death(data, player);
}

void		routine_food(t_data *data)
{
	t_tlist		*team;
	t_plist		*plist;
	t_player	*player;
	t_timeval	now;

	gettimeofday(&now, NULL);
	team = data->teams;
	while (team)
	{
		plist = team->list;
		while (plist)
		{
			player = plist->player;
			plist = plist->next;
			check_player(data, player, &now);
		}
		team = team->next;
	}
}
