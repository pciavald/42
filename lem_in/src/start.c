/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:03:36 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:50 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			display(t_ant *ant, t_room *room)
{
	ft_putchar('L');
	ft_putnbr(ant->id);
	ft_putchar('-');
	ft_putstr(room->name);
	ft_putchar(' ');
}

void			add_path(t_data *data, t_ant *ant, t_room *room)
{
	t_around	*around;

	around = (t_around *)malloc(sizeof(t_around));
	around->room = room;
	if (ant->path && ft_strcmp(ant->path->room->name, data->end->name))
	{
		ant->path->room->ants = 0;
		around->next = ant->path;
	}
	else
		around->next = NULL;
	ant->path = around;
	room->ants++;
}

static void		start2(t_data *data, t_around *around, t_ant *ant)
{
	while (around)
	{
		if (around->room->ants == 0)
		{
			display(ant, around->room);
			add_path(data, ant, around->room);
			if (ant->next)
			{
				ant = ant->next;
				data->start->ants--;
			}
			else
			{
				data->start->ants = 0;
				break ;
			}
		}
		around = around->next;
	}
}

void			start(t_data *data)
{
	t_ant		*ant;
	t_around	*around;

	if (data->start->ants)
	{
		ant = data->ants;
		while (ant)
		{
			if (ant->path)
				ant = ant->next;
			else
				break ;
		}
		if (ant == NULL)
			return ;
		around = data->start->around;
		start2(data, around, ant);
	}
}
