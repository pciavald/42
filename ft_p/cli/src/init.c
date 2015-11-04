/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 22:04:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:20:04 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	usage(char *pname)
{
	printf("Usage: %s <addr> <port>\n", pname);
	exit(-1);
}

void	quit(int sock)
{
	close(sock);
	exit(0);
}

char	**init_cmd_tab(void)
{
	int		i;
	char	**cmd_tab;

	cmd_tab = (char **)malloc(sizeof(char *) * CMD_N + 1);
	i = 0;
	while (i <= CMD_N)
		cmd_tab[i++] = (char *)malloc(sizeof(char) * 5);
	cmd_tab[0] = "ls";
	cmd_tab[1] = "cd";
	cmd_tab[2] = "get";
	cmd_tab[3] = "put";
	cmd_tab[4] = "pwd";
	cmd_tab[5] = "quit";
	cmd_tab[6] = "help";
	cmd_tab[7] = NULL;
	return (cmd_tab);
}

int		create_client(char *addr, int port)
{
	int				sock;
	t_protoent		proto;
	t_sin			sin;

	proto = getprotobyname("tcp");
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
