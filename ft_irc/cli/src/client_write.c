/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 06:31:26 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 20:36:14 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	client_write(t_env *e, int s)
{
	char	*data;
	int		r;

	data = e->fds[s].buf_read;
	r = read(0, data, BUF_SIZE);
	if (r >= 0)
	{
		data[r++] = '\0';
		send(s, data, ft_strlen(data), 0);
		ft_bzero(data, r);
		ft_putstr(PROMPT);
	}
	else
		exit(0);
}
