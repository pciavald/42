/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:28:33 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:28:40 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 43 || *str == 45)
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		ret = 10 * ret + (*str++ - '0');
	return (sign * ret);
}
