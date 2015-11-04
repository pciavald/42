/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:20:20 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:50:04 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pie X Y R\n" - Fin de l’incantation sur la case donnée avec le
** résultat R (0 ou 1).
*/

#include "server.h"
#include <stdio.h>

void	gui_pie(void *param, int cs)
{
	t_spell	*spell;

	spell = (t_spell*)param;
	dprintf(cs, "pie %d %d %d\n", spell->x, spell->y, spell->success);
}
