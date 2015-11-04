/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_broadcast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:42:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:16:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	gui_broadcast(t_data *data, void (*gui_msg)(void*, int), void *arg)
{
	int		i;

	i = 0;
	while (i < data->max_fd)
	{
		if (data->fds[i].type == FD_GUI)
			gui_msg(arg, i);
		i++;
	}
}
