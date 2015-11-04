/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pbc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:57:35 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 08:14:54 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pbc #n M\n" - Un joueur fait un broadcast
*/

#include "server.h"
#include <stdio.h>

void	gui_pbc(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "pbc #%d %s\n", player->cs, player->msg);
}
