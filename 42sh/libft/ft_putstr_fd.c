/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:01:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:46:47 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putstr_fd(char const *s, int fd)
{
	int		len;

	if (!s)
		return ((int)write(fd, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return ((int)write(fd, s, len));
}
