/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:01:50 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 04:32:58 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pic X Y L #n #n …\n" - Premier joueur lance l’incantation pour tous les
** suivants sur la case
*/

#include "server.h"
#include <stdio.h>

void	gui_pic(void *param, int cs)
{
	t_spell	*spell;
	t_plist	*plist;

	spell = (t_spell*)param;
	dprintf(cs, "pic %d %d %d #%d", spell->x, spell->y, spell->level,
			spell->owner->cs);
	plist = spell->plist;
	while (plist)
	{
		dprintf(cs, " #%d", plist->player->cs);
		plist = plist->next;
	}
	dprintf(cs, "\n");
}
