/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:24:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 11:06:46 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_pin(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pin #%d %d %d %d %d %d %d %d %d %d\n", player->cs, player->x,
			player->y, player->food, player->linemate, player->deraumere,
			player->sibur, player->mendiane, player->phiras, player->thystame);
}
