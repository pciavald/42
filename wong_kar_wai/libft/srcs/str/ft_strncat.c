/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:26:46 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:26:47 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1])
		index1++;
	while (s2[index2] && index2 < n)
	{
		s1[index1 + index2] = s2[index2];
		index2++;
	}
	s1[index1 + index2] = 0;
	return (s1);
}
