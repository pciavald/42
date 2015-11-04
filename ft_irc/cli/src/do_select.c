/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:11:10 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 14:04:56 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdlib.h>

void	init_fd(t_env *e)
{
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	FD_SET(0, &e->fd_read);
	FD_SET(e->s, &e->fd_read);
}

void	do_select(t_env *e)
{
	struct timeval		tv;

	tv.tv_sec = 5;
	e->r = select(e->s + 1, &e->fd_read, &e->fd_write, NULL, &tv);
}

void	check_fd(t_env *e)
{
	if (e->r)
	{
		if (FD_ISSET(0, &e->fd_read))
			client_write(e, e->s);
		else if (FD_ISSET(e->s, &e->fd_read))
			client_read(e, e->s);
	}
}
