/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:40:45 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/20 12:40:50 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	char	value;

	value = c % 256;
	tmp = b;
	while (len--)
		*tmp++ = value;
	return (b);
}
