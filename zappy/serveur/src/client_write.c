/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 18:05:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:18:13 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/socket.h>
#include <string.h>

void	client_write(t_data *data, int cs)
{
	size_t	blen;

	if ((blen = strlen(data->fds[cs].buf_write)))
		send(cs, data->fds[cs].buf_write, blen, 0);
	bzero(data->fds[cs].buf_write, BUF_SIZE + 1);
}
