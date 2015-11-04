/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:38:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 14:09:21 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	prompt(t_env *e)
{
	e->nick = nick(e->s);
	while (42)
	{
		init_fd(e);
		do_select(e);
		check_fd(e);
	}
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc != 3)
		usage(argv[0]);
	e.s = create_client(argv[1], ft_atoi(argv[2]));
	init_fds(&e, e.s);
	prompt(&e);
	close(e.s);
	return (0);
}
