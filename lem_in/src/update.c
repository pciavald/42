/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:59:01 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:58 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		update_curr2(t_room *room, t_around *origin)
{
	t_around	*tmp;

	tmp = room->curr->next;
	while (tmp)
	{
		if (tmp->room->ants == 0)
		{
			room->curr = tmp;
			break ;
		}
		else if (tmp->next == NULL)
		{
			tmp = room->around;
			continue ;
		}
		else if (tmp->next == origin)
		{
			room->curr = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}

int				update_curr(t_room *room)
{
	t_around	*tmp;
	t_around	*origin;

	if (room->curr)
		origin = room->curr;
	if (room->curr && room->curr->next == NULL)
		room->curr->next = room->around;
	if (room->curr == NULL)
	{
		tmp = room->around;
		while (tmp)
		{
			if (tmp->room->ants == 0)
			{
				room->curr = tmp;
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
		update_curr2(room, origin);
	return (1);
}
