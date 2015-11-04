/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:32:15 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 07:30:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_bct(void *param, int cs)
{
	t_square	*square;

	square = (t_square*)param;
	dprintf(cs, "bct %d %d %d %d %d %d %d %d %d\n",
			square->x,
			square->y,
			square->food,
			square->linemate,
			square->deraumere,
			square->sibur,
			square->mendiane,
			square->phiras,
			square->thystame);
}
