/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 11:17:51 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:49:03 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

static void		player_place_egg(t_data *data, t_egg *egg, t_player *player)
{
	player->x = egg->x;
	player->y = egg->y;
	player->o = egg->o;
	gui_broadcast(data, gui_ebo, egg);
	gui_broadcast(data, gui_pnw, player);
	egg_del(&data->eggs, egg);
}

static void		player_place_new(t_data *data, t_player *player)
{
	srand(time(NULL));
	player->x = rand() % data->x;
	player->y = rand() % data->y;
	player->o = rand() % 4 + 1;
	gui_broadcast(data, gui_pnw, player);
}

static void		player_place(t_data *data, t_tlist *team, t_player *player)
{
	t_egg	*egg;
	t_egg	*current;

	egg = NULL;
	current = data->eggs;
	while (current)
	{
		if (current->ready && !strcmp(current->team, team->name)
				&& (!egg || current->food < egg->food))
			egg = current;
		current = current->next;
	}
	if (egg)
		player_place_egg(data, egg, player);
	else
		player_place_new(data, player);
}

void			player_init(t_data *data, t_tlist *team, int cs)
{
	t_player	*player;

	player = &data->fds[cs].player;
	player->team = strdup(team->name);
	player->cs = cs;
	player->level = 1;
	player->food = 10;
	gettimeofday(&player->food_t, NULL);
	player->linemate = 0;
	player->deraumere = 0;
	player->sibur = 0;
	player->mendiane = 0;
	player->phiras = 0;
	player->thystame = 0;
	player->msg = NULL;
	player->drop = -1;
	player->get = -1;
	player->actions = NULL;
	player->spell = NULL;
	player_place(data, team, player);
	player_add(&team->list, player);
}
