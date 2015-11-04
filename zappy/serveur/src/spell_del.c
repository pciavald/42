/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 05:28:03 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:32:33 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	spell_del(t_spell **list, t_spell *spell)
{
	t_spell	*current;

	if (*list == spell)
		*list = spell->next;
	else
	{
		current = *list;
		while (current->next && current->next != spell)
			current = current->next;
		current->next = current->next->next;
	}
	while (spell->plist)
		player_del(&spell->plist, spell->plist->player);
	free(spell);
}
