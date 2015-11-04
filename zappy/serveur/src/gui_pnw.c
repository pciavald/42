/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pnw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:43:45 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 23:54:47 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_pnw(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pnw #%d %d %d %d %d %s\n", player->cs, player->x, player->y,
			player->o, player->level, player->team);
}
