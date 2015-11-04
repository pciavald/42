/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 22:35:25 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 13:49:33 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_line	*new_node(char *line)
{
	t_line		*node;

	node = (t_line *)malloc(sizeof(t_line));
	if (node)
	{
		node->line = ft_strdup(line);
		node->next = NULL;
	}
	return (node);
}

static void		add_line(t_data *data, char *line)
{
	t_line		*node;

	if (!data->file)
		data->file = new_node(line);
	else
	{
		node = data->file;
		while (node->next)
			node = node->next;
		node->next = new_node(line);
	}
}

void			read_file(t_data *data)
{
	char		*line;
	int			line_nb;
	int			ret;

	line_nb = 0;
	line = NULL;
	while ((ret = get_next_line(STDIN, &line)))
	{
		add_line(data, line);
		ft_strdel(&line);
		line_nb++;
	}
}
