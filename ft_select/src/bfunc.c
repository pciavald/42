/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:16:13 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/20 03:09:34 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putendl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
