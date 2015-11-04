/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_invent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:09:37 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/26 16:27:29 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void			ccmd_invent(t_data *data, int cs, char **cmd, t_timeval **t)
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
	player = &(data->fds[cs].player);
	dprintf(cs, "{nourriture %i, ", player->food);
	dprintf(cs, "linemate %i, ", player->linemate);
	dprintf(cs, "deraumere %i, ", player->deraumere);
	dprintf(cs, "sibur %i, ", player->sibur);
	dprintf(cs, "mendiane %i, ", player->mendiane);
	dprintf(cs, "thystame %i}\n", player->thystame);
}
