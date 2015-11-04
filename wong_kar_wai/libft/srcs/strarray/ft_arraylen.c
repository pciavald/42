/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:42:22 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:42:28 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_arraylen(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
		index++;
	return (index);
}
