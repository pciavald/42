/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:13:30 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:48:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>

static void	routine_action2(t_data *data, t_player *player)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	if (!player->spell && player->actions && !player->actions->timer)
		player->actions->action(data, player->cs, player->actions->cmd,
								&player->actions->timer);
	else if (!player->spell && player->actions
				&& time_diff(player->actions->timer, &now) >= 0)
	{
		player->actions->action(data, player->cs, player->actions->cmd,
								&player->actions->timer);
		action_delfirst(&player->actions);
	}
}

void		routine_action(t_data *data)
{
	t_tlist		*team;
	t_plist		*list;

	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			routine_action2(data, list->player);
			list = list->next;
		}
		team = team->next;
	}
}
