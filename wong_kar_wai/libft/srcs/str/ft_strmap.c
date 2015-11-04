/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:32:44 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:32:46 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*tmp;
	unsigned int	index;

	index = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[index])
	{
		tmp[index] = f(s[index]);
		index++;
	}
	tmp[index] = 0;
	return (tmp);
}
