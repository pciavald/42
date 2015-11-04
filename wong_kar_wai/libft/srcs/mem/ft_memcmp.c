/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:25:06 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:25:10 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	if (!s1 || !s2)
		return (0);
	while (n--)
	{
		if ((*tmp1 - *tmp2) != 0)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}
