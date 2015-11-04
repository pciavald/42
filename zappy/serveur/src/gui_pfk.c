/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pfk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:22:22 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 01:40:56 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pfk #n\n" - Le joueur pond un œuf
*/

#include "server.h"
#include <stdio.h>

void	gui_pfk(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pfk #%d\n", player->cs);
}
