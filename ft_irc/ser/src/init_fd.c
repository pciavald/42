/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:12:10 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 08:57:57 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/select.h>
#include "bircd.h"

void	init_fd(t_env *e)
{
	int		i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i < e->maxfd)
	{
		if (e->fds[i].type != FD_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (strlen(e->fds[i].buf_write) > 0)
				FD_SET(i, &e->fd_write);
			e->max = MAX(e->max, i);
		}
		i++;
	}
}
