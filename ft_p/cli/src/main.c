/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:38:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:21:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		parse(char *cmd, int sock)
{
	int				i;
	static char		**cmd_tab;
	char			**split;

	cmd_tab = init_cmd_tab();
	split = ft_strsplit(cmd, ' ');
	if (ft_strequ(split[0], "quit"))
		quit(sock);
	i = 0;
	while (i < CMD_N)
	{
		if (ft_strequ(split[0], cmd_tab[i]))
		{
			send(sock, cmd, ft_strlen(cmd), 0);
			ft_freesplit(&split);
			return (1);
		}
		i++;
	}
	ft_freesplit(&split);
	ft_putendl("command not found");
	return (0);
}

int		receive(int sock)
{
	char	buf[BUF_SIZE];
	int		len;

	len = recv(sock, buf, BUF_SIZE, 0);
	buf[len] = '\0';
	ft_putstr(buf);
	return (len);
}

void	prompt(int sock)
{
	char	*line;
	char	*cmd;
	int		ret;
	int		len;

	line = NULL;
	ft_putstr("<ft_p client> ");
	while ((ret = get_next_line(0, &line)))
	{
		cmd = ft_strtrim(line);
		parse(cmd, sock);
		ft_strdel(&line);
		ft_strdel(&cmd);
		len = BUF_SIZE;
		while (len == BUF_SIZE)
			len = receive(sock);
		receive(sock);
		ft_putstr("<ft_p client> ");
	}
}

int		main(int argc, char **argv)
{
	int			port;
	int			sock;

	if (argc != 3)
		usage(argv[0]);
	port = ft_atoi(argv[2]);
	sock = create_client(argv[1], port);
	prompt(sock);
	close(sock);
	return (0);
}
