/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 22:04:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:09:47 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_fds(t_env *e, int sock)
{
	e->fds = (t_fd *)malloc(sizeof(t_fd) * (sock + 1));
}

int		create_client(char *addr, int port)
{
	int				sock;
	t_protoent		proto;
	t_hostent		host;
	t_sin			sin;

	proto = getprotobyname("tcp");
	host = gethostbyname(addr);
	addr = inet_ntoa(*((struct in_addr *)host->h_addr));
	if (proto == 0)
	{
		ft_putstr("could not get protocol 'tcp'.\n");
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)))
	{
		ft_putstr("Please try again later or select another port.\n");
		exit(-1);
	}
	return (sock);
}
