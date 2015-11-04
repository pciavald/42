/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_spell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 04:22:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:47:25 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

void	do_spell(t_data *data, t_spell *spell)
{
	t_plist	*plist;

	if (spell_check(data, spell->owner, END))
		spell->success = 1;
	gui_broadcast(data, gui_pie, spell);
	plist = spell->plist;
	while (plist)
	{
		plist->player->level += spell->success;
		dprintf(plist->player->cs, "niveau actuel : %d\n",
				plist->player->level);
		gui_broadcast(data, gui_plv, plist->player);
		plist = plist->next;
	}
	if (spell->success)
	{
		disperse(data, spell);
		win_check(data);
	}
}

void	routine_spell(t_data *data)
{
	t_spell		*spell;
	t_timeval	now;

	gettimeofday(&now, NULL);
	spell = data->spells;
	while (spell)
	{
		if (time_diff(&spell->timer, &now) >= 0)
		{
			do_spell(data, spell);
			spell_del(&data->spells, spell);
			routine_spell(data);
			return ;
		}
		spell = spell->next;
	}
}
