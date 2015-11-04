/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:26:52 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:01:57 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmpd;
	const char	*tmps;
	size_t		count;
	size_t		maxnlen;

	tmpd = dst;
	tmps = src;
	count = size;
	while (count-- && *tmpd)
		tmpd++;
	maxnlen = tmpd - dst;
	count = size - maxnlen;
	if (!count)
		return (maxnlen + ft_strlen(tmps));
	while (*tmps)
	{
		if (count != 1)
		{
			*tmpd++ = *tmps;
			count--;
		}
		tmps++;
	}
	*tmpd = 0;
	return (maxnlen + (tmps - src));
}
