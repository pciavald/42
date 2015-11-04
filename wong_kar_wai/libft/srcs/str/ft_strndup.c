/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:04:08 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/23 14:10:50 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	index;

	index = 0;
	dup = (char*)malloc(sizeof(char) * (n + 1));
	if (dup)
	{
		while (index < n)
		{
			dup[index] = s1[index];
			index++;
		}
		dup[index] = 0;
	}
	return (dup);
}
