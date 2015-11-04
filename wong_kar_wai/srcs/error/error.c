/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 06:47:12 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:13:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <errno.h>

void	error(char *err, char *arg, int quit)
{
	if (err)
		ft_putstr_fd(err, 2);
	if (arg)
		ft_putendl_fd(arg, 2);
	else
		ft_putchar_fd('\n', 2);
	if (errno != 0)
		perror(NULL);
	if (quit)
		exit(-1);
}
