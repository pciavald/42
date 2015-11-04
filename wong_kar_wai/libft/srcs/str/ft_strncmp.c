/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:28:19 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:28:21 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s2 > *s1)
			return (-1);
		else if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
