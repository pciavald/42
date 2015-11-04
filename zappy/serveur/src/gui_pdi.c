/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:30:07 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 02:41:10 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pdi #n\n" - Le joueur est mort de faim.
*/

#include "server.h"
#include <stdio.h>

void	gui_pdi(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pdi #%d\n", player->cs);
}
