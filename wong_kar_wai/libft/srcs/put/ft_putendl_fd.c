/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 04:54:01 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 20:22:56 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
