/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:05:52 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:22:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"
#include <sys/socket.h>

void	change_nickname(t_env *e, int cs, char **cmd)
{
	char	*msg;
	char	*nick;

	if (is_valid(cmd, 1))
	{
		nick = e->fds[cs].nickname;
		msg = ft_strjoin("has a new nickname: ", cmd[1]);
		s_info(e, nick, msg, e->fds[cs].channel);
		ft_strdel(&msg);
		ft_bzero(nick, 10);
		ft_strncpy(nick, cmd[1], ft_strlen(cmd[1]) - 1);
		ft_freesplit(&cmd);
	}
	else
		send(cs, "[syntaxe : /nick <nickname[1-9 chars]>]\n",
				ft_strlen("[syntaxe : /nick <nickname[1-9 chars]>]\n"), 0);
}

void	join_channel(t_env *e, int cs, char **cmd)
{
	char	*nick;
	char	*chan;

	if (is_valid(cmd, 2))
	{
		nick = e->fds[cs].nickname;
		chan = e->fds[cs].channel;
		s_info(e, nick, "left.\n", chan);
		ft_bzero(chan, 50);
		ft_strncpy(chan, cmd[1], ft_strlen(cmd[1]) - 1);
		s_info(e, nick, "has joined the room\n", chan);
		ft_freesplit(&cmd);
	}
	else
		send(cs, "[syntaxe : /join <channel[1-50 chars]>]\n",
				ft_strlen("[syntaxe : /join <channel[1-50 chars]>]\n"), 0);
}

void	leave_channel(t_env *e, int cs, char **cmd)
{
	char	*nick;
	char	*chan;

	if (cmd[1] == NULL)
	{
		nick = e->fds[cs].nickname;
		chan = e->fds[cs].channel;
		s_info(e, nick, "left.\n", chan);
		ft_bzero(chan, 50);
		ft_freesplit(&cmd);
	}
	else
		send(cs, "[syntaxe : /leave]\n", ft_strlen("[syntaxe : /leave]\n"), 0);
}

void	who(t_env *e, int cs)
{
	int		i;

	i = 0;
	send(cs, "logged users on this channel :\n",
			ft_strlen("logged users on this channel :\n"), 0);
	while (i < e->maxfd)
	{
		if (ft_strequ(e->fds[i].channel, e->fds[cs].channel))
		{
			send(cs, e->fds[i].nickname, ft_strlen(e->fds[i].nickname), 0);
			send(cs, "\n", 1, 0);
		}
		i++;
	}
}

void	pmessage(t_env *e, int cs, char **cmd)
{
	int		i;
	char	msg[ft_strlen(e->fds[cs].nickname) + ft_strlen(cmd[2]) + 4];

	if (is_valid(cmd, 3))
	{
		i = 0;
		while (i < e->maxfd)
		{
			if (ft_strequ(e->fds[i].nickname, cmd[1]))
			{
				ft_strcat(msg, "[");
				ft_strcat(msg, e->fds[cs].nickname);
				ft_strcat(msg, "] ");
				ft_strcat(msg, cmd[2]);
				ft_strcat(msg, "\n");
				send(i, msg, ft_strlen(msg), 0);
				return ;
			}
			i++;
		}
		send(i, "user not found\n", ft_strlen("user not found\n"), 0);
	}
	else
		send(cs, "[syntaxe : /msg <nick> <word>]\n",
				ft_strlen("[syntaxe : /msg <nick> <word>]\n"), 0);
}
