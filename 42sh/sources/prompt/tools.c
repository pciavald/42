/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 01:00:21 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/16 04:54:28 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <stdlib.h>

t_char		*cur_char(t_char *c, int i)
{
	if (i > 0)
	{
		while (i > 2)
		{
			c = c->next;
			i--;
		}
	}
	else
	{
		while (c->next)
			c = c->next;
	}
	return (c);
}

int			listlen(t_char *c)
{
	int	i;

	i = 0;
	while (c)
	{
		c = c->next;
		i++;
	}
	return (i);
}

t_char		*dup_char(t_char *lechar)
{
	t_char			*c;

	c = NULL;
	if (lechar)
	{
		c = (t_char *)malloc(sizeof(t_char));
		c->c = lechar->c;
		c->next = lechar->next;
	}
	return (c);
}

t_char		*dup_str(t_char *orig)
{
	t_char	*c;
	t_char	*tmp;
	t_char	*dup;

	c = dup_char(orig);
	tmp = c;
	dup = orig;
	while (tmp)
	{
		tmp->next = dup_char(dup->next);
		tmp = tmp->next;
		dup = dup->next;
	}
	return (c);
}

t_line		*dup_line(t_line *orig)
{
	t_line			*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->id = orig->id;
	line->line = dup_str(orig->line);
	line->tmp = dup_str(orig->tmp);
	line->edit = orig->edit;
	line->prev = NULL;
	line->next = NULL;
	return (line);
}
