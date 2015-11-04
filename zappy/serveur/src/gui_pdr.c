/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pdr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:24:42 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 07:42:02 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pdr #n i\n" - Le joueur jette une ressource.
*/

#include "server.h"
#include <stdio.h>

void	gui_pdr(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pdr #%d %d\n", player->cs, player->drop);
}
