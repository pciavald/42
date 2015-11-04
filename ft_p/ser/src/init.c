/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 16:55:31 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 21:11:41 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		create_server(int port)
{
	int				sock;
	t_protoent		proto;
	t_sin			sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
	{
		ft_putstr("Could not get protocol 'tcp'.\n");
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)))
	{
		ft_putstr("Please try again later or select another port.\n");
		exit(-1);
	}
	listen(sock, 42);
	print_c("[Server running.\t\t]\n", GREEN);
	ft_putstr("[use ctrl-c to exit.\t\t]\n");
	return (sock);
}

void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		print_c("[goodbye.\t\t\t]\n", GREEN);
		exit(0);
	}
}
