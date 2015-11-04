/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:27:35 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:27:37 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	index;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		index = 0;
		while (s1[index] == s2[index])
		{
			index++;
			if (!s2[index])
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
