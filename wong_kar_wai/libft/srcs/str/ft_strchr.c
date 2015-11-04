/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:27:04 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:27:06 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)(c % 256);
	while (*s != cc)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
