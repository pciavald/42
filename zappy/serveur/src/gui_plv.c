/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_plv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:19:51 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 05:34:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_plv(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "plv #%d %d\n", player->cs, player->level);
}
