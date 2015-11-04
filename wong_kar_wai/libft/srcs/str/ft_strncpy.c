/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:26:16 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:26:19 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strncpy(char *s1, const char *s2, size_t n)
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
