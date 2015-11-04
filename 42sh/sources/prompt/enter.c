/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 00:56:21 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:58:55 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <prompt.h>
#include <proto.h>
#include <term.h>
#include <unistd.h>
#include <libft.h>

static t_line	*add_to_history(t_line *line)
{
	t_data	*d;

	d = data();
	line->id = d->max_id++;
	if (d->history)
	{
		d->history->prev = line;
		line->next = d->history;
	}
	d->history = line;
	return (NULL);
}

static void		del_tmp(t_line *line)
{
	if (line->tmp)
	{
		line->line = del_str(line->line);
		line->line = line->tmp;
		line->tmp = NULL;
	}
}

static int		handle_enter(t_data *d)
{
	t_line	*l;
	t_line	*dup;

	if (d->cur == CURRENT && d->current && d->current->edit)
	{
		d->current->line = d->current->tmp;
		d->current->tmp = NULL;
		d->current = add_to_history(d->current);
		return (1);
	}
	else if (d->cur != NONE && d->cur != CURRENT)
	{
		d->current = del_line(d->current);
		l = d->history;
		while (l->id != d->cur)
			l = l->next;
		if (l->edit)
		{
			dup = dup_line(l);
			add_to_history(dup);
			del_tmp(dup);
			return (1);
		}
	}
	return (0);
}

void			clean_history_tmp(void)
{
	t_line	*tmp;

	tmp = data()->history;
	while (tmp)
	{
		tmp->edit = -1;
		tmp->tmp = del_str(tmp->tmp);
		tmp = tmp->next;
	}
}

int				is_enter(char *key)
{
	if (key[0] == '\n' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		show_line(1);
		tputchar('\n');
		if (handle_enter(data()))
		{
			data()->run = 1;
			treset(data());
			lexer(data()->history->line);
			nl_handler();
			tinit(data());
			data()->run = 0;
		}
		clean_history_tmp();
		if (data()->cur != NONE)
			data()->cur = CURRENT;
		prompt();
		return (1);
	}
	return (0);
}
