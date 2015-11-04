/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 00:40:41 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:52:20 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <prompt.h>
#include <proto.h>
#include <stdlib.h>

static t_char	*add_char(char key, t_char *orig, int i)
{
	t_char		*c;
	t_char		*cur;

	c = (t_char *)malloc(sizeof(t_char));
	c->c = key;
	if (orig)
	{
		if (i == 1)
			c->next = orig;
		else
		{
			cur = cur_char(orig, i);
			c->next = cur->next;
			cur->next = c;
			return (orig);
		}
	}
	else
		c->next = NULL;
	return (c);
}

static t_line	*init_line(char key)
{
	t_line		*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->id = 0;
	line->line = NULL;
	line->tmp = add_char(key, NULL, 0);
	line->prev = NULL;
	line->next = NULL;
	line->edit = -1;
	return (line);
}

static void		set_edit(t_line *l)
{
	if (l->edit > 0)
		l->edit++;
	if (!l->edit)
		l->edit = -1;
}

static void		ascii(char key)
{
	t_line		*l;

	if (data()->cur == NONE)
		data()->current = init_line(key);
	else if (data()->cur == CURRENT)
	{
		l = data()->current;
		if (l == NULL)
			l = init_line(key);
		else
			l->tmp = add_char(key, l->tmp, l->edit);
		set_edit(l);
		data()->current = l;
	}
	else
	{
		l = data()->history;
		while (l->id != data()->cur)
			l = l->next;
		if (l->tmp == NULL && l->edit)
			l->tmp = dup_str(l->line);
		l->tmp = add_char(key, l->tmp, l->edit);
		set_edit(l);
	}
}

int				is_ascii(char *key)
{
	if (ft_isascii(key[0]) && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		if (ft_isprint(key[0]))
		{
			ascii(key[0]);
			if (data()->cur == NONE)
				data()->cur = CURRENT;
			return (1);
		}
	}
	return (0);
}
