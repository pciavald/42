/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:50:05 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 18:51:08 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printsplit(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		ft_putendl(split[i++]);
}
