/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 00:07:09 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:16:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt.h>
#include <proto.h>
#include <signal.h>

void	sigctrlc(void)
{
	if (!data()->run)
		show_line(1);
	if (data()->cur != NONE)
	{
		clean_history_tmp();
		data()->cur = CURRENT;
		if (data()->current)
		{
			if (data()->current->line)
				data()->current->line = del_str(data()->current->line);
			if (data()->current->tmp)
				data()->current->tmp = del_str(data()->current->tmp);
			data()->current->edit = 0;
		}
	}
	tputchar('\n');
	if (!data()->run)
		show_line(0);
}

void	ignore(void)
{
	return ;
}

void	sighandler(int signum)
{
	if (signum == SIGINT)
		sigctrlc();
	if (signum == SIGTSTP)
		ignore();
	if (signum == SIGQUIT)
		ignore();
	if (signum == SIGHUP)
		ignore();
}
