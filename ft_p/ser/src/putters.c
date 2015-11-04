/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 21:24:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:29:32 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_status(int stat, int cs)
{
	if (stat == ERROR)
	{
		send(cs, RED, ft_strlen(RED), 0);
		send(cs, "ERROR", ft_strlen("ERROR"), 0);
		send(cs, NC, ft_strlen(NC), 0);
	}
	else
	{
		send(cs, GREEN, ft_strlen(GREEN), 0);
		send(cs, "SUCCESS", ft_strlen("SUCCESS"), 0);
		send(cs, NC, ft_strlen(NC), 0);
	}
}

void	client_connect(int id)
{
	print_c("[Client #", GREEN);
	print_c(ft_itoa(id), RED);
	print_c(" connected.\t\t]\n", GREEN);
}

void	client_quit(int id)
{
	print_c("[Connection #", RED);
	print_c(ft_itoa(id), RED);
	print_c(" closed by peer.\t]\n", RED);
}

void	usage(char *pname)
{
	ft_putstr("Usage: ");
	ft_putstr(pname);
	ft_putstr("<port>\n");
	exit(-1);
}

void	print_c(char *str, char *c)
{
	ft_putstr(c);
	ft_putstr(str);
	ft_putstr(NC);
}
