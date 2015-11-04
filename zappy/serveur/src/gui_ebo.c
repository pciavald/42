/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ebo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:34:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:49:08 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "ebo #e\n" - Un joueur s’est connecté pour l’œuf
*/
#include "server.h"
#include <stdio.h>
void	gui_ebo(void *param, int cs)
{
	t_egg	*egg;

	egg = (t_egg*)param;
	dprintf(cs, "ebo #%d\n", egg->id);
}
