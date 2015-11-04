/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 19:48:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 22:28:03 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** return 1 if t2 > t1
*/

#include "server.h"
#include <sys/time.h>

int		time_diff(t_timeval *t1, t_timeval *t2)
{
	t_timeval	t3;

	t3.tv_sec = t2->tv_sec - t1->tv_sec;
	t3.tv_usec = t2->tv_usec - t1->tv_usec;
	if (t3.tv_sec > 0 || (t3.tv_sec == 0 && t3.tv_usec > 0))
		return (1);
	if (t3.tv_sec < 0 || (t3.tv_sec == 0 && t3.tv_usec < 0))
		return (-1);
	return (0);
}
