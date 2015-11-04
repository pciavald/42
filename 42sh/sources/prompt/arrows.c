/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 19:49:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 16:09:39 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <macro.h>
#include <prompt.h>
#include <proto.h>
#include <termcap.h>
#include <unistd.h>

int				is_arrow_up(char *key)
{
	if ((key[0] == 27 && key[1] == '[' && key[2] == '5' && key[3] == '~')
			|| (key[0] == 27 && key[1] == '[' && key[2] == 'A' && key[3] == 0))
	{
		if (data()->cur == NONE || data()->cur == 1)
			write(1, "\a", 1);
		else if (data()->cur == CURRENT && data()->history)
			data()->cur = data()->history->id;
		else if (data()->history)
			data()->cur--;
		return (1);
	}
	return (0);
}

int				is_arrow_down(char *key)
{
	if ((key[0] == 27 && key[1] == '[' && key[2] == '6' && key[3] == '~')
			|| (key[0] == 27 && key[1] == '[' && key[2] == 'B' && key[3] == 0))
	{
		if (data()->cur == NONE || data()->cur == CURRENT)
			write(1, "\a", 1);
		else if (data()->history && data()->cur == data()->history->id)
			data()->cur = CURRENT;
		else if (data()->history)
			data()->cur++;
		return (1);
	}
	return (0);
}

static void		edit_handle(t_line *l, int i, char sign)
{
	if (sign < 0 && l->edit)
	{
		if (l->edit == -1)
			l->edit = i;
		else if (l->edit != 1)
			l->edit--;
		else
			write(1, "\a", 1);
	}
	else if (l->edit)
	{
		if (l->edit == -1)
			write(1, "\a", 1);
		else if (l->edit == i)
			l->edit = -1;
		else
			l->edit++;
	}
}

int				is_arrow_right(char *key)
{
	t_line	*l;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'C' && key[3] == 0)
	{
		if (data()->cur == NONE)
			write(1, "\a", 1);
		else if (data()->cur == CURRENT && data()->current)
		{
			l = data()->current;
			edit_handle(l, listlen(l->tmp), 1);
		}
		else if (data()->cur != CURRENT)
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
			if (l->tmp)
				edit_handle(l, listlen(l->tmp), 1);
			else
				edit_handle(l, listlen(l->line), 1);
		}
		return (1);
	}
	return (0);
}

int				is_arrow_left(char *key)
{
	t_line	*l;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'D' && key[3] == 0)
	{
		if (data()->cur == NONE)
			write(1, "\a", 1);
		else if (data()->cur == CURRENT && data()->current)
		{
			l = data()->current;
			edit_handle(l, listlen(l->tmp), -1);
		}
		else if (data()->cur != CURRENT)
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
			if (l->tmp)
				edit_handle(l, listlen(l->tmp), -1);
			else
				edit_handle(l, listlen(l->line), -1);
		}
		return (1);
	}
	return (0);
}
