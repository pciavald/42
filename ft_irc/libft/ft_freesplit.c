/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:37:20 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 18:39:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplit(char ***split)
{
	int		i;

	i = 0;
	while ((*split)[i])
	{
		ft_strdel(&((*split)[i]));
		i++;
	}
	free(*split);
	*split = NULL;
}
