/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:38:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/17 18:36:12 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		get_sock(char *leport)
{
	static int		sock = -1;
	int				port;

	if (sock < 0)
	{
		port = ft_atoi(leport);
		sock = create_server(port);
	}
	return (sock);
}

int		main(int argc, char **argv)
{
	int			sock;

	signal(SIGCHLD, SIG_IGN);
	signal(SIGINT, sighandler);
	if (argc != 2)
		usage(argv[0]);
	sock = get_sock(argv[1]);
	run(sock);
	return (0);
}
