/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:10:18 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 21:25:34 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"

void	get_nick(t_env *e, int cs, char *info)
{
	printf("client #%d has a nickname : %s", cs, info);
	ft_strncpy(e->fds[cs].nickname, info, ft_strlen(info) - 1);
}

void	get_chan(t_env *e, int cs, char *info)
{
	printf("client #%d joined a channel : #%s", cs, info);
	s_info(e, e->fds[cs].nickname, "has joined the room\n", info);
	ft_strncpy(e->fds[cs].channel, info, ft_strlen(info) - 1);
}

int		receive(t_env *e, int cs, char *info)
{
	int		ret;
	int		*i;

	i = &(e->fds[cs].i);
	ret = recv(cs, info + (*i % BUF_SIZE), BUF_SIZE, 0);
	*i += ret;
	if (info[(*i - 1) % BUF_SIZE] == '\n')
	{
		*i = 0;
		return (1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}

void	client_read(t_env *e, int cs)
{
	int		r;
	char	*info;

	info = e->fds[cs].buf_read;
	r = receive(e, cs, info);
	if (r == 0)
	{
		printf("client #%d (%s) gone away\n", cs, e->fds[cs].nickname);
		close(cs);
		clean_fd(&e->fds[cs]);
	}
	else if (r == 1)
	{
		if (e->fds[cs].nickname[0] == '\0')
			get_nick(e, cs, info);
		else if (e->fds[cs].channel[0] == '\0')
			get_chan(e, cs, info);
		else
			parse(e, cs, info);
		ft_bzero(info, ft_strlen(info));
	}
}
