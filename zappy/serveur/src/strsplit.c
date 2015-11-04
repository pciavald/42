/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:02:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 20:10:57 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

static int		countwords(char const *s, char c)
{
	int		words;
	int		in_a_word;

	words = 0;
	while (*s)
	{
		in_a_word = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			in_a_word = 1;
			s++;
		}
		if (in_a_word)
			words += 1;
	}
	return (words);
}

static size_t	splitlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**strsplit(char const *s, char c)
{
	char	**wordlist;
	size_t	len;
	int		words;
	int		i;

	i = 0;
	words = countwords(s, c);
	wordlist = (char **)malloc((words + 1) * sizeof(char *));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = splitlen(s, c);
			wordlist[i++] = strsub(s, 0, len);
			s += len;
		}
	}
	wordlist[i] = NULL;
	return (wordlist);
}
