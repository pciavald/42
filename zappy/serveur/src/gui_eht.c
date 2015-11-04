/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_eht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:33:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 06:48:20 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "eht #e\n" - L’œuf éclot.
*/

#include "server.h"
#include <stdio.h>

void	gui_eht(void *param, int cs)
{
	t_egg	*egg;

	egg = (t_egg*)param;
	dprintf(cs, "eht #%d\n", egg->id);
}
