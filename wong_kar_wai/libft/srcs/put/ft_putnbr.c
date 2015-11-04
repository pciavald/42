/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 05:09:35 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:09:46 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int	index;
	int	digit[10];

	index = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n >= 10)
	{
		digit[index++] = n % 10 + '0';
		n = n / 10;
	}
	digit[index] = n + '0';
	while (index >= 0)
		write(1, digit + index--, 1);
}
