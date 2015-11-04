/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:54 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:00:22 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char				*ft_strtrim(char const *s)
{
	unsigned int	st;
	char			*tmp;
	size_t			l;

	st = 0;
	l = ft_strlen(s);
	if (l == 0)
		return (ft_strnew(0));
	l--;
	tmp = (char *)s;
	while (tmp[st] == 32 || tmp[st] == 9 || tmp[st] == 10)
		st++;
	while (l && tmp[l] && (tmp[l] == 32 || tmp[l] == 9 || tmp[l] == 10))
		l--;
	return (ft_strsub(s, st, (&tmp[l] - &tmp[st] + 1)));
}
