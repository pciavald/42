/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 16:30:43 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:09:46 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		invalid(char *str, size_t len)
{
	if (ft_strlen(str) > len)
		return (1);
	if (ft_strlen(str) == 0)
		return (1);
	while (*str)
	{
		if (!ft_isprint(*str))
			return (1);
		str++;
	}
	return (0);
}

char	*chan(int cs, char *nick)
{
	char	*chan;

	ft_putstr("choose a channel to join : #");
	get_next_line(0, &chan);
	while (invalid(chan, 49))
	{
		ft_putendl("Please enter a channel between 1 and 49 chars long.");
		ft_strdel(&chan);
		ft_putstr("join channel : #");
		get_next_line(0, &chan);
	}
	ft_putstr("Welcome to channel ");
	ft_putstr(chan);
	ft_putstr(", ");
	ft_putendl(nick);
	ft_putstr(PROMPT);
	send(cs, chan, ft_strlen(chan), 0);
	send(cs, "\n", 1, 0);
	return (chan);
}

char	*nick(int cs)
{
	char	*nickname;

	ft_putstr("\e[1;1H\e[2J");
	ft_putstr("nickname : ");
	get_next_line(0, &nickname);
	while (invalid(nickname, 9))
	{
		ft_putendl("Please enter a nickname between 1 and 9 chars long.");
		ft_strdel(&nickname);
		ft_putstr("nickname : ");
		get_next_line(0, &nickname);
	}
	send(cs, nickname, ft_strlen(nickname), 0);
	send(cs, "\n", 1, 0);
	chan(cs, nickname);
	return (nickname);
}
