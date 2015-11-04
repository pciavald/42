/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:34:04 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:29:40 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	int			count;
	size_t		index;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
		{
			while (s[index] && s[index] != c)
				index++;
			count++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tmp;
	size_t		index;
	size_t		len;
	size_t		count;

	index = 0;
	count = ft_wordcount(s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	count = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			len = 0;
			while (s[index + len] && s[index + len] != c)
				len++;
			tmp[count++] = ft_strsub(s, index, len);
			index = index + len;
		}
	}
	tmp[count] = NULL;
	return (tmp);
}
