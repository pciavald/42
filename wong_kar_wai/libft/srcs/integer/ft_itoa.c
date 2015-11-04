/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:34:18 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:34:19 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	ret[11];
	int		sign;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	sign = (n < 0) ? -1 : 1;
	while (sign * n > 9 || sign * n < 0)
	{
		ret[i++] = '0' + sign * (n % 10);
		n = n / 10;
	}
	ret[i++] = '0' + sign * n;
	if (sign == -1)
		ret[i++] = '-';
	if (!(tmp = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	tmp[i] = 0;
	while (i--)
		tmp[i] = ret[j++];
	return (tmp);
}
