/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:52:58 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 22:27:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		free_split(char **array)
{
	int		index;

	index = 0;
	while (array[index])
		ft_strdel(&array[index++]);
	free(array);
}

int			count_split(char **array)
{
	int		count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}
