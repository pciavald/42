/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:27:22 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:12:17 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	size_t	len;

	len = ft_strlen(s);
	cc = (char)(c % 256);
	while (s[len] != cc)
	{
		if (!len)
			return (NULL);
		len--;
	}
	return ((char *)(s + len));
}
