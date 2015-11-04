/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 17:19:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:15:25 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		receive(t_env *e, int cs, char *buf)
{
	int		ret;
	int		*i;

	i = &(e->i);
	ret = recv(cs, buf + (*i % BUF_SIZE), BUF_SIZE, 0);
	*i += ret;
	if (buf[(*i - 1) % BUF_SIZE] == '\n')
	{
		*i = 0;
		return (1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}

void	client_read(t_env *e, int s)
{
	int		r;
	char	*msg;

	msg = e->fds[s].buf_read;
	r = receive(e, s, msg);
	if (r == 0)
	{
		printf("connection to server lost.\n");
		close(e->s);
		exit(0);
	}
	else if (r == 1)
	{
		ft_putstr("\b\b\b\b");
		ft_putstr(msg);
		ft_bzero(msg, BUF_SIZE);
		ft_putstr(PROMPT);
	}
}
