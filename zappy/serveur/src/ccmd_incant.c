/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_incant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:37:09 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:46:41 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

t_plist			*get_players(t_data *data, t_player *player, t_spell *spell)
{
	t_plist		*plist;
	t_tlist		*team;
	t_plist		*list;

	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			if (list->player->x == player->x && list->player->y == player->y
					&& list->player->level == player->level && !player->spell)
			{
				player_add(&plist, list->player);
				list->player->spell = spell;
				dprintf(list->player->cs, "elevation en cours\n");
			}
			list = list->next;
		}
		team = team->next;
	}
	return (plist);
}

void			ccmd_incant(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	t_spell		*spell;
	t_timeval	now;

	(void)cmd;
	(void)t;
	gettimeofday(&now, NULL);
	player = &(data->fds[cs].player);
	if (spell_check(data, player, START))
	{
		spell = (t_spell*)malloc(sizeof(t_spell));
		spell->x = player->x;
		spell->y = player->y;
		spell->owner = player;
		spell->plist = get_players(data, player, spell);
		spell->timer = time_add(data, &now, INCANT_T);
		spell->success = 0;
		spell->next = data->spells;
		data->spells = spell;
		gui_broadcast(data, gui_pic, spell);
	}
	else
		dprintf(cs, "ko\n");
}
