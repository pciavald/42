/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:28:40 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/20 17:29:29 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (n--)
		*tmp1++ = *tmp2++;
	return (s1);
}
