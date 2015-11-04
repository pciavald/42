/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:04:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 11:14:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>

void	init_server(t_data *data)
{
	struct sockaddr_in		sin;
	struct protoent			*proto;
	int						sock;

	if (!(proto = (struct protoent*)getprotobyname("tcp")))
		error(data->name);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		error(data->name);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(data->port);
	if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
		error(data->name);
	if (listen(sock, 42) == -1)
		error(data->name);
	data->fds[sock].type = FD_SERV;
	data->fds[sock].fct_read = srv_accept;
}
