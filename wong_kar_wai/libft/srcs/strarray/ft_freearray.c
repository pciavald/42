/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:42:22 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:42:28 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_freearray(char **array, int clear)
{
	size_t	index;

	index = 0;
	if (clear)
	{
		while (array[index])
		{
			free(array[index]);
			index++;
		}
	}
	free(array);
}
