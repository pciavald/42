/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:01:43 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 15:02:53 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsplit(char **split)
{
	int		size;

	size = 0;
	if (split && *split)
	{
		while (split[size])
			size++;
	}
	return (size);
}
