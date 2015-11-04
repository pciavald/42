/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:31:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:48:07 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void	ccmd_right(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	t_timeval	now;

	if (!(*t))
	{
		gettimeofday(&now, NULL);
		*t = (t_timeval*)malloc(sizeof(t_timeval));
		**t = time_add(data, &now, MOVE_T);
		return ;
	}
	(void)cmd;
	player = &data->fds[cs].player;
	player->o = (player->o % 4) + 1;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
