/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:11:25 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/21 14:33:43 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bircd.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, USAGE, av[0]);
		exit(1);
	}
	e->port = atoi(av[1]);
}
