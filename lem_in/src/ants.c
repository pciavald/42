/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 12:04:21 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:16 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_ants(t_data *data)
{
	t_ant		*ant;
	t_ant		*tmp;
	int			count;

	count = 1;
	while (count <= data->ants_nb)
	{
		ant = (t_ant *)malloc(sizeof(t_ant));
		ant->id = count++;
		ant->path = NULL;
		ant->next = NULL;
		tmp = data->ants;
		if (tmp == NULL)
			data->ants = ant;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ant;
		}
	}
}

void	update(t_data *data)
{
	t_ant		*ant;
	t_room		*next;

	if (data->ants)
	{
		ant = data->ants;
		while (ant)
		{
			if (ant->path == NULL)
				break ;
			next = choose(data, ant->path->room);
			if (next)
			{
				display(ant, next);
				add_path(data, ant, next);
			}
			ant = ant->next;
		}
	}
}

void	diffuse(t_around *path)
{
	while (path)
	{
		path->room->pher++;
		path = path->next;
	}
}

void	check_arrived(t_data *data)
{
	t_ant	*ant;
	t_ant	*prev;

	ant = data->ants;
	prev = data->ants;
	while (ant)
	{
		if (ant->path && !ft_strcmp(ant->path->room->name, data->end->name))
		{
			diffuse(ant->path);
			if (ant == data->ants && !ant->next)
				data->ants = NULL;
			else if (ant == data->ants)
				data->ants = ant->next;
			else if (ant->next == NULL)
				prev->next = NULL;
			else
				prev->next = ant->next;
			data->end->ants++;
		}
		prev = ant;
		ant = ant->next;
	}
}

void	lem_in(t_data *data)
{
	data->start->ants = data->ants_nb;
	while (data->ants)
	{
		update(data);
		check_arrived(data);
		start(data);
		ft_putchar('\n');
	}
}
