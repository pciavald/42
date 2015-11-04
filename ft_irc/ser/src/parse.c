/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 14:59:04 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 21:55:37 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"
#include <sys/socket.h>

void	parse(t_env *e, int cs, char *cmd)
{
	char	**split;

	if (cmd[0] == '/')
	{
		cmd++;
		split = ft_strsplit(cmd, ' ');
		if (ft_strnequ(split[0], "nick", ft_strlen("nick")))
			change_nickname(e, cs, split);
		else if (ft_strnequ(split[0], "join", ft_strlen("join")))
			join_channel(e, cs, split);
		else if (ft_strequ(cmd, "leave\n"))
			leave_channel(e, cs, split);
		else if (ft_strequ(cmd, "who\n"))
			who(e, cs);
		else if (ft_strnequ(split[0], "msg", ft_strlen("msg")))
			pmessage(e, cs, split);
		else
			send(cs, "unknown command or bad usage\n",
					ft_strlen("unknown command or bad usage\n"), 0);
	}
	else
		client_write(e, cs);
}
