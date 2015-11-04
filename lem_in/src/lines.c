/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 21:32:59 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_line	*is_cmd(t_data *data, t_line *line)
{
	t_line		*ret;

	data->state = 0;
	if (line->line[1] == '#')
	{
		if (!ft_strcmp(line->line, START))
			data->state = 1;
		else if (!ft_strcmp(line->line, END))
			data->state = 2;
	}
	return ((ret = data->state ? line->next : line));
}

static void		is_ant_nb(t_data *data, char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_splitlen(split) == 1 && !ft_strchr(line, '-'))
		data->ants_nb = ft_atoi(line);
	ft_splitdel(&split);
}

static void		is_room(t_data *data, char *line)
{
	char		**split;
	t_room		*room;

	split = ft_strsplit(line, ' ');
	if (ft_splitlen(split) == 3 && split[0][0] != 'L')
	{
		room = add_room(data, split);
		if (data->state == 1)
			data->start = room;
		if (data->state == 2)
			data->end = room;
	}
	ft_splitdel(&split);
}

static void		is_tube(t_data *data, char *line)
{
	char		**split;

	split = ft_strsplit(line, '-');
	if (ft_splitlen(split) == 2)
		add_tube(data, split);
	ft_splitdel(&split);
}

void			parse_lines(t_data *data)
{
	t_line		*line;

	line = data->file;
	while (line)
	{
		line = is_cmd(data, line);
		if (line->line[0] && line->line[0] != '#')
		{
			is_ant_nb(data, line->line);
			is_room(data, line->line);
			is_tube(data, line->line);
		}
		line = line->next;
	}
}
