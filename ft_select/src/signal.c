/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:23:40 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/20 03:09:54 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sigctrlc(int signum)
{
	if (signum == SIGINT)
		treset(datast());
	exit(-1);
}

void	sigctrlz(int signum)
{
	char	cp[2];
	t_data	*data;

	if (signum == SIGTSTP)
	{
		data = datast();
		cp[0] = data->term.c_cc[VSUSP];
		cp[1] = 0;
		tcsetattr(0, 0, &(data->buterm));
		tputs(tgetstr("te", NULL), 1, tputchar);
		tputs(tgetstr("ve", NULL), 1, tputchar);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}

void	sigfg(int signum)
{
	t_data	*data;

	if (signum == SIGCONT)
	{
		data = datast();
		tcsetattr(0, 0, &(data->term));
		tputs(tgetstr("ti", NULL), 1, tputchar);
		tputs(tgetstr("vi", NULL), 1, tputchar);
		display(data);
	}
}

void	sigwinch(int signum)
{
	if (signum == SIGWINCH)
	{
		reinit();
		display(datast());
	}
}
