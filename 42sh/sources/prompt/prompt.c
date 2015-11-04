/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 22:41:53 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 20:55:55 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <proto.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include <macro.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>
#include <libft.h>

static void		put_pwd(void)
{
	char	buf[MAXPATHLEN];
	char	*home;
	char	*cwd;
	int		len;

	home = ft_getenv(*data()->envp, "HOME");
	cwd = getcwd(buf, MAXPATHLEN);
	if (home)
		len = ft_strlen(home);
	if (home && ft_strnequ(home, cwd + 13, len - 1))
	{
		tputstr("~");
		tputstr(cwd + len + 13);
	}
	else if (cwd)
		tputstr(cwd);
	else
		tputstr("...");
	if (home)
		free(home);
}

static void		tputcharhl(char c)
{
	tputs(tgetstr(HLON, NULL), 1, tputchar);
	tputchar(c);
	tputs(tgetstr(HLOFF, NULL), 1, tputchar);
}

static void		tputlist(t_char *c, int i, int enter)
{
	int	j;

	j = 1;
	while (c)
	{
		if (i == j && !enter)
			tputcharhl(c->c);
		else
			tputchar(c->c);
		c = c->next;
		j++;
	}
	if (i == -1 && !enter)
		tputcharhl(' ');
}

void			prompt(void)
{
	char	*user;

	user = ft_getenv(*data()->envp, "USER");
	tputs(tgetstr(CLEARLINE, NULL), 1, tputchar);
	tputs(tgetstr(BEGIN, NULL), 1, tputchar);
	tputstr("[");
	tputstr("\033[0;32m");
	if (user)
	{
		tputstr(user);
		free(user);
	}
	else
		tputstr("Anonymous");
	tputstr("\033[0m");
	tputstr("] @ [");
	tputstr("\033[0;32m");
	put_pwd();
	tputstr("\033[0m");
	tputstr("] > ");
}

void			show_line(int enter)
{
	t_data		*d;
	t_line		*l;

	d = data();
	prompt();
	if (d->cur == NONE || (d->cur == CURRENT && !d->current)
			|| (d->cur == CURRENT && d->current && !d->current->edit))
	{
		if (!enter)
			tputcharhl(' ');
	}
	else if (d->cur == CURRENT)
		tputlist(d->current->tmp, d->current->edit, enter);
	else
	{
		l = d->history;
		while (l->id != d->cur)
			l = l->next;
		if (l->tmp && l->edit)
			tputlist(l->tmp, l->edit, enter);
		else if (l->edit)
			tputlist(l->line, l->edit, enter);
		else if (!enter)
			tputcharhl(' ');
	}
}
