/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:24:12 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:24:17 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	char	cc;

	cc = (char)c;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (n--)
	{
		*tmp1 = *tmp2;
		tmp1++;
		if (*tmp2 == cc)
			return ((void *)(tmp1));
		tmp2++;
	}
	return (NULL);
}
