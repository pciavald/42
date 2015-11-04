/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:03:19 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 14:03:54 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_splitdel(char ***split)
{
	int		index;

	if (split && *split)
	{
		index = 0;
		while ((*split)[index])
			ft_strdel(&(*split)[index++]);
		*split = NULL;
	}
}

int		ft_splitlen(char **split)
{
	int		len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}
