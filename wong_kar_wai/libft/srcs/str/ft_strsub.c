/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:34 by tcharlat          #+#    #+#             */
/*   Updated: 2014/03/23 18:35:03 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (ft_strnew(0));
	tmp[len] = 0;
	while (len--)
		tmp[len] = s[start + len];
	return (tmp);
}
