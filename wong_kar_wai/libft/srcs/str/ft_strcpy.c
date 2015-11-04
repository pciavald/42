/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:26:02 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:26:05 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strcpy(char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s2[index])
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = 0;
	return (s1);
}
