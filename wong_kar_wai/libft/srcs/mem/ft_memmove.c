/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:24:35 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:24:38 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s2[index] && index < n)
	{
		s1[index] = s2[index];
		index++;
	}
	while (index < n)
		s1[index++] = 0;
	return (s1);
}

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	safe[n];

	ft_strncpy(safe, (const char *)s2, n);
	ft_strncpy((char *)s1, (const char *)safe, n);
	return (s1);
}
