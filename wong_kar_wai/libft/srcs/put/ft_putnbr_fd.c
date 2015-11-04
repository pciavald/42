/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:40:42 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:28:17 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	index;
	int	digit[10];

	index = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	while (n >= 10)
	{
		digit[index++] = n % 10 + '0';
		n = n / 10;
	}
	digit[index] = n + '0';
	while (index >= 0)
		write(fd, digit + index--, 1);
}
