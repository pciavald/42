/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:30:54 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:30:55 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * size);
	if (!tmp)
		return (NULL);
	while (size--)
		tmp[size] = 0;
	return ((void *)tmp);
}
