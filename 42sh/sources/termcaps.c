/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 00:05:36 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:11:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include <proto.h>

static void	flags(t_termios *term)
{
	term->c_lflag ^= ICANON;
	term->c_lflag ^= ECHO;
}

void		tputstr(char *str)
{
	write(isatty(1), str, ft_strlen(str));
}

int			tputchar(int c)
{
	write(isatty(1), &c, 1);
	return (1);
}

void		treset(t_data *data)
{
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
	tputs(tgetstr(HIDCURSOR, NULL), 1, tputchar);
}

void		tinit(t_data *data)
{
	tcgetattr(0, &(data->term));
	tcgetattr(0, &(data->buterm));
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
	tputs(tgetstr(SHWCURSOR, NULL), 1, tputchar);
}
