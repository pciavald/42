/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:55:03 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 15:55:05 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprintnstr(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (!ft_isprint(str[i++]))
			return (0);
	}
	return (1);
}
