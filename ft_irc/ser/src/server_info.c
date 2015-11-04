/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 14:38:15 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 20:49:04 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"
#include <sys/socket.h>

void	s_info(t_env *e, char *nm, char *info, char *chan)
{
	int		i;
	char	msg[ft_strlen(nm) + ft_strlen(info) + 2];

	ft_strcat(msg, nm);
	ft_strcat(msg, " ");
	ft_strcat(msg, info);
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if (ft_strequ(e->fds[i].channel, chan))
				send(i, msg, ft_strlen(msg), 0);
		}
		i++;
	}
}
