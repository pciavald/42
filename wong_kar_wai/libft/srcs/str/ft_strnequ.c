/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:23 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:33:25 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	if (!n)
		return (1);
	while (*tmp1 == *tmp2)
	{
		n--;
		if (!*tmp1 || !n)
			return (1);
		tmp1++;
		tmp2++;
	}
	return (0);
}
