/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 16:41:09 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:39:55 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		get(char **split, int sock)
{
	int		i;
	int		fd;
	t_stat	stat;
	void	*map;

	i = 1;
	while (split[i])
	{
		if ((fd = open(split[i], O_RDONLY)) > 2)
		{
			fstat(fd, &stat);
			map = mmap(0, stat.st_size, PROT_READ, MAP_SHARED, fd, 0);
			send(sock, map, stat.st_size, 0);
			munmap(map, stat.st_size);
			close(fd);
		}
		else
			(void)sock;
		i++;
	}
	return (0);
}

int		put(char **split, int sock)
{
	(void)split;
	(void)sock;
	return (0);
}

int		cd(char **split, int sock)
{
	(void)split;
	(void)sock;
	return (0);
}

char	**init_nm_tab(void)
{
	char	**nm_tab;
	int		i;

	nm_tab = (char **)malloc(sizeof(char *) * FN_N);
	i = 0;
	while (i < FN_N)
		nm_tab[i++] = (char *)malloc(sizeof(char) * 5);
	nm_tab[0] = "get";
	nm_tab[1] = "put";
	nm_tab[2] = "cd";
	nm_tab[3] = "quit";
	nm_tab[4] = "help";
	return (nm_tab);
}
