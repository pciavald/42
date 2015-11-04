/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 16:52:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:29:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*executable(char **str)
{
	char	**split;

	split = ft_strsplit(*str, ' ');
	if (ft_strequ(split[0], "ls") || ft_strequ(split[0], "pwd"))
	{
		*str = split[0];
		if (split[1])
			return (split[1]);
		return ("");
	}
	return (NULL);
}
