/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sbp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:48:08 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:13:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "sbp\n" - Mauvais paramètres pour la commande
*/

#include "stdio.h"

void	gui_sbp(void *null, int cs)
{
	(void)null;
	dprintf(cs, "sbp\n");
}
