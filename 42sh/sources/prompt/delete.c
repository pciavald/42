/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 01:42:25 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:58:08 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt.h>
#include <proto.h>
#include <stdlib.h>
#include <unistd.h>

static void		del_char(t_char *c, int i)
{
	t_char	*t;

	c = cur_char(c, i);
	if (c->next)
	{
		t = c->next;
		c->next = c->next->next;
		free(t);
	}
}

static void		backspace_handle(t_line *l)
{
	t_char	*tmp;

	if (!l->tmp && l->edit != 0)
		l->tmp = dup_str(l->line);
	if (l->edit > 2)
		del_char(l->tmp, l->edit - 1);
	else if (l->edit == 2 || (l->edit == -1 && listlen(l->tmp) == 1))
	{
		tmp = l->tmp;
		l->tmp = l->tmp->next;
		free(tmp);
	}
	else if (l->edit == -1)
		del_char(l->tmp, listlen(l->tmp));
	else
		write(1, "\a", 1);
	if (!l->tmp)
		l->edit = 0;
	else if (l->edit != -1)
		l->edit--;
}

static void		delete_handle(t_line *l)
{
	t_char	*tmp;

	if (!l->tmp && l->edit != 0)
		l->tmp = dup_str(l->line);
	if (l->edit > 1)
		del_char(l->tmp, l->edit);
	else if (l->edit == 1)
	{
		tmp = l->tmp;
		l->tmp = l->tmp->next;
		free(tmp);
	}
	else
		write(1, "\a", 1);
	if (!l->tmp)
		l->edit = 0;
	else if (l->edit > listlen(l->tmp))
		l->edit = -1;
}

int				is_delete(char *key)
{
	t_line	*l;

	if (key[0] == 27 && key[1] == '[' && key[2] == '3' && key[3] == '~')
	{
		if (data()->cur == NONE || (data()->cur == CURRENT && !data()->current))
		{
			write(1, "\a", 1);
			return (1);
		}
		else if (data()->cur == CURRENT)
			l = data()->current;
		else
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
		}
		if (l->edit == -1)
			write(1, "\a", 1);
		else
			delete_handle(l);
		return (1);
	}
	return (0);
}

int				is_backspace(char *key)
{
	t_line	*l;

	if (key[0] == 127 && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		if (data()->cur == NONE || (data()->cur == CURRENT && !data()->current))
		{
			write(1, "\a", 1);
			return (1);
		}
		else if (data()->cur == CURRENT)
			l = data()->current;
		else
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
		}
		if (l->edit == 1)
			write(1, "\a", 1);
		else
			backspace_handle(l);
		return (1);
	}
	return (0);
}
