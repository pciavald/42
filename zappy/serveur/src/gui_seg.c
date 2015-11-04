/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_seg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:43:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:16:33 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "seg N\n" - Fin du jeu. L’équipe donnée remporte la partie.
*/

#include "server.h"
#include <stdio.h>

void	gui_seg(void *param, int cs)
{
	t_tlist	*team;

	team = (t_tlist*)param;
	dprintf(cs, "seg %s\n", team->name);
}
