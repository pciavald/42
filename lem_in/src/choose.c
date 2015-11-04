/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:09:24 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:24 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*choose2(t_room *next, t_room *room, int max_pher)
{
	if (max_pher == 0)
	{
		update_curr(room);
		if (room->curr)
			return (room->curr->room);
		else
			return (NULL);
	}
	return (next);
}

t_room	*choose(t_data *data, t_room *room)
{
	t_room		*next;
	t_room		*tmp;
	t_around	*around;
	t_around	*origin;
	int			max_pher;

	max_pher = 0;
	around = room->around;
	tmp = NULL;
	next = NULL;
	origin = around;
	while (around)
	{
		tmp = around->room;
		if (!ft_strcmp(around->room->name, data->end->name))
			return (around->room);
		if (!tmp->ants && tmp->pher >= max_pher && ((next = tmp) == tmp))
			max_pher = tmp->pher;
		around = around->next;
		if (around == origin)
			break ;
	}
	return (choose2(next, room, max_pher));
}
