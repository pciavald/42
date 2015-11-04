/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:01:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:46:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putstr(char const *s)
{
	int		len;

	if (!s)
		return ((int)write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return ((int)write(1, s, len));
}
