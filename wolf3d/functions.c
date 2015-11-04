/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:15:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int				ft_char_int(char c)
{
	int			tmp;

	tmp = c -'0';
	return (tmp);
}

int				ft_atoi(const char *str)
{
	int			nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (*str - '0');
		str++;
	}
	return (nb * sign);
}

double			ft_abs(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

double			ft_square(double x)
{
	return (x * x);
}
