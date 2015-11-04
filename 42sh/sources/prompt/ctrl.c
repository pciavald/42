/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 23:53:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:53:02 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <macro.h>
#include <prompt.h>
#include <proto.h>
#include <unistd.h>
#include <term.h>

static int	exit_handler(void)
{
	show_line(1);
	treset(data());
	return (EXIT);
}

int			is_ctrl_a(char *key)
{
	t_line	*l;

	if ((key[0] == 1 && key[1] == 0 && key[2] == 0 && key[3] == 0)
			|| (key[0] == 27 && key[1] == '[' && key[2] == 'H' && key[3] == 0))
	{
		if ((data()->cur == NONE)
				|| (data()->cur == CURRENT && !data()->current)
				|| (data()->cur == CURRENT && !data()->current->edit))
			return (1);
		else if (data()->cur != CURRENT && data()->cur != NONE)
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
			if (l->edit)
				l->edit = 1;
		}
		else
			data()->current->edit = 1;
		return (1);
	}
	return (0);
}

int			is_ctrl_d(char *key)
{
	t_line	*l;

	if (key[0] == 4 && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		if ((data()->cur == NONE)
				|| (data()->cur == CURRENT && !data()->current)
				|| (data()->cur == CURRENT && !data()->current->edit))
			return (exit_handler());
		else if (data()->cur != CURRENT && data()->cur != NONE)
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
			if (!l->edit)
				return (exit_handler());
		}
		write(1, "\a", 1);
		return (1);
	}
	return (0);
}

int			is_ctrl_l(char *key)
{
	if (key[0] == 12 && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		tputstr(CLEARCHAR);
		prompt();
		return (1);
	}
	return (0);
}

int			is_other(char *key)
{
	(void)key;
	return (1);
}
