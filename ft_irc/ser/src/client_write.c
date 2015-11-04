/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:10:49 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:09:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include "bircd.h"

char	*make_message(char *nick, char *msg)
{
	int		len;
	char	*message;

	len = ft_strlen(nick) + ft_strlen(msg) + 4;
	message = (char *)XV(NULL, malloc(sizeof(char) * len), "malloc");
	ft_bzero(message, len);
	ft_strcat(message, "<");
	ft_strcat(message, nick);
	ft_strcat(message, "> ");
	ft_strcat(message, msg);
	return (message);
}

void	client_write(t_env *e, int cs)
{
	char	*nick;
	char	*chan;
	char	*msg;
	int		i;

	nick = e->fds[cs].nickname;
	chan = e->fds[cs].channel;
	msg = make_message(nick, e->fds[cs].buf_read);
	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && (i != cs))
		{
			if (ft_strequ(e->fds[i].channel, chan))
				send(i, msg, ft_strlen(msg), 0);
		}
		i++;
	}
	ft_strdel(&msg);
}
