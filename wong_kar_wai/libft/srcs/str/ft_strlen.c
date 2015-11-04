/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:25:27 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:29:15 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlen(const char *s)
{
	char	*tmp;
	size_t	count;

	tmp = (char *)s;
	count = 0;
	while (*tmp++)
		count++;
	return (count);
}
