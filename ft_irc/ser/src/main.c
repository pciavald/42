/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:12:30 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 18:50:50 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int		main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	get_opt(&e, ac, av);
	srv_create(&e, e.port);
	ft_putendl("\e[1;1H\e[2Jwelcome to ft_irc :)\nserver ready.");
	main_loop(&e);
	return (0);
}
