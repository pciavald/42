/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:25:49 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:25:52 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char*)malloc(sizeof(char) * len + 1);
	if (dup)
	{
		while (len + 1 > 0)
		{
			dup[len] = s1[len];
			len--;
		}
	}
	return (dup);
}
