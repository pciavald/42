/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 21:32:52 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:45:15 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			init_room(t_room *room, char **split)
{
	room->name = ft_strdup(split[0]);
	room->pos[0] = ft_atoi(split[1]);
	room->pos[1] = ft_atoi(split[2]);
	room->ants = 0;
	room->pher = 0;
	room->around = NULL;
	room->next = NULL;
}

t_room				*add_room(t_data *data, char **split)
{
	t_room			*room;
	t_room			*tmp;

	room = (t_room *)malloc(sizeof(t_room));
	if (data->rooms == NULL)
		data->rooms = room;
	else
	{
		tmp = data->rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
	init_room(room, split);
	return (room);
}

static void			add_neighbour(t_room *r1, t_room *r2)
{
	t_around		*nb;
	t_around		*tmp;

	nb = (t_around *)malloc(sizeof(t_around));
	tmp = r1->around;
	if (!tmp)
		r1->around = nb;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = nb;
	}
	nb->room = r2;
	nb->next = NULL;
}

void				add_tube(t_data *data, char **split)
{
	t_room			*tmp;
	t_room			*room1;
	t_room			*room2;

	tmp = data->rooms;
	while (tmp)
	{
		if (!ft_strcmp(split[0], tmp->name))
			room1 = tmp;
		else if (!ft_strcmp(split[1], tmp->name))
			room2 = tmp;
		tmp = tmp->next;
	}
	add_neighbour(room1, room2);
	add_neighbour(room2, room1);
}
