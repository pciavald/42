/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:53:10 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 01:00:43 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pex #n\n" - Un joueur expulse
*/

#include "server.h"
#include <stdio.h>

void	gui_pex(void *param, int cs)
{
	t_player *player;

	player = (t_player*)param;
	dprintf(cs, "pex #%d\n", player->cs);
}
