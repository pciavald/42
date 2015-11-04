/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:37:47 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 11:44:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "sgt T\n" "sgt\n" Demande de l’unité de temps courante sur le serveur
*/

#include "server.h"
#include <stdio.h>

void	gui_sgt(void *param, int cs)
{
	t_data	*data;

	data = (t_data*)param;
	dprintf(cs, "sgt %d\n", data->time);
}
