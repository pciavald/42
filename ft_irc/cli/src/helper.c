/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 17:11:01 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 14:07:25 by pciavald         ###   ########.fr       */
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
