/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:49:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	init_data(&data, av);
	init_server(&data);
	while ("loop")
	{
		init_fd(&data);
		data.sel = select(data.fd_nb + 1, &data.fd_read, &data.fd_write,
				NULL, &data.timeout);
		check_fd(&data);
		routine_food(&data);
		routine_egg(&data);
		routine_spell(&data);
		routine_action(&data);
	}
	return (0);
}
