/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:58:11 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 09:16:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>

t_timeval		time_add(t_data *data, t_timeval *time, int coef)
{
	t_timeval				t;
	long unsigned int		sum;

	sum = (time->tv_sec * 1000000) + time->tv_usec
		+ (1000000 / data->time * coef);
	t.tv_sec = sum / 1000000;
	t.tv_usec = sum % 1000000;
	return (t);
}
