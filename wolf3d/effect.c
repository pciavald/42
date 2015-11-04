/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:14:53 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_wolf3d.h"

int				check_color(int angle, int hor, int ver)
{
	if (hor == 1)
	{
		if (angle >= 0 && angle < 180)
			return (150);
		if (angle >= 180 && angle < 360)
			return (100);
	}
	else if (ver == 1)
	{
		if (angle >= 90 && angle < 270)
			return (50);
		if (angle >= 270 || angle < 90)
			return (200);
	}
	return (0);
}

