/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:48:22 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:45:05 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_data	*init(void)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data)
	{
		data->file = NULL;
		data->ants_nb = 0;
		data->ants = NULL;
		data->state = 0;
		data->rooms = NULL;
		data->start = NULL;
		data->starting = 0;
		data->end = NULL;
	}
	return (data);
}

void	error(char *str)
{
	if (str)
		ft_putendl(str);
	exit(0);
}

void	check_graph(t_data *data)
{
	int			count;
	t_around	*start;

	if (data->ants_nb < 1)
		error(ERROR);
	if (!data->start)
		error(ERROR);
	if (!data->end)
		error(ERROR);
	if (!data->rooms)
		error(ERROR);
	start = data->start->around;
	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	if (count == 0)
		error("No room linked to spawn.");
	data->starting = count;
}

int		main(void)
{
	t_data		*data;

	data = init();
	read_file(data);
	parse_lines(data);
	check_graph(data);
	init_ants(data);
	lem_in(data);
	return (0);
}
