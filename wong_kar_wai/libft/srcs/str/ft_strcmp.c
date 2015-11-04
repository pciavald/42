/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:27:57 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:02:22 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] == s2[index]) && s1[index] && s2[index])
		index++;
	if (s1[index] || s2[index])
		return (s1[index] - s2[index]);
	return (0);
}
