/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 18:59:03 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/13 14:37:19 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_fd(t_data *data)
{
	int		i;

	data->fd_nb = 0;
	FD_ZERO(&data->fd_read);
	FD_ZERO(&data->fd_write);
	i = -1;
	while (++i < data->max_fd)
	{
		if (data->fds[i].type != FD_FREE)
		{
			FD_SET(i, &data->fd_read);
			if (*data->fds[i].buf_write)
				FD_SET(i, &data->fd_write);
			data->fd_nb = (data->fd_nb > i) ? data->fd_nb : i;
		}
	}
}
