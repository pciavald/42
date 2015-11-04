/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_edi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:36:19 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 02:42:10 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "edi #e\n" - L’œuf éclos est mort de faim.
*/

#include "server.h"
#include <stdio.h>

void	gui_edi(void *param, int cs)
{
	t_egg	*egg;

	egg = (t_egg*)param;
	dprintf(cs, "edi #%d\n", egg->id);
}
