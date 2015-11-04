/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nl_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 00:56:21 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:22:49 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <macro.h>
#include <proto.h>
#include <term.h>

void		nl_handler(void)
{
	char			buf[32];
	int				i;

	i = 0;
	tinit(data());
	write(1, "\033[6n", 4);
	read(0, buf, 32);
	while (buf[i] != ';')
		i++;
	if (buf[i + 1] != '1' || buf [i + 2] != 'R')
	{
		tputs(tgetstr(HLON, NULL), 1, tputchar);
		tputstr("%\n");
		tputs(tgetstr(HLOFF, NULL), 1, tputchar);
	}
	treset(data());
}
