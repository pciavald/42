/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:30:49 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:46:21 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void	ccmd_forward(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	t_timeval	now;

	if (*t == NULL)
	{
		gettimeofday(&now, NULL);
		*t = (t_timeval*)malloc(sizeof(t_timeval));
		**t = time_add(data, &now, MOVE_T);
		return ;
	}
	(void)cmd;
	player = &data->fds[cs].player;
	if (player->o == N)
		player->y = mod(player->y - 1, data->y);
	else if (player->o == S)
		player->y = mod(player->y + 1, data->y);
	else if (player->o == W)
		player->x = mod(player->x - 1, data->x);
	else if (player->o == E)
		player->x = mod(player->x + 1, data->x);
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
