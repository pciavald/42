/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:24:50 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:26:55 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (!s)
		return (NULL);
	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == c % 256)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
