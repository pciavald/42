/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:19:24 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "header_wolf3d.h"

int				move_front(t_env *e)
{
	e->p.x += (GRID * e->speed) * e->cos[e->p.a * 10];
	e->p.y += (GRID * e->speed) * e->sin[e->p.a * 10];
	if (e->map[e->p.y / GRID][e->p.x / GRID] == 1)
	{
		e->p.x -= (GRID * e->speed) * e->cos[e->p.a * 10];
		e->p.y -= (GRID * e->speed) * e->sin[e->p.a * 10];
	}
	else if (e->map[e->p.y / GRID][e->p.x / GRID] == 2 && e->fov > 40)
	{
		init_p(e);
		e->fov -= 20;
		e->disto = GRID * ((double)(WIN_X / 2) / e->tan[(e->fov / 2) * 10]);
	}
	return (0);
}

int				move_back(t_env *e)
{
	e->p.x -= (GRID * e->speed) * e->cos[e->p.a * 10];
	e->p.y -= (GRID * e->speed) * e->sin[e->p.a * 10];
	if (e->map[e->p.y / GRID][e->p.x / GRID] == 1)
	{
		e->p.x += (GRID * e->speed) * e->cos[e->p.a * 10];
		e->p.y += (GRID * e->speed) * e->sin[e->p.a * 10];
	}
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode != ESC)
	{
		if (keycode == LEFT)
		{
			e->p.a += 2;
			if (e->p.a >= 360)
				e->p.a -= 360;
		}
		if (keycode == UP)
			move_front(e);
		if (keycode == RIGHT)
		{
			e->p.a -= 3;
			if (e->p.a <= 0)
				e->p.a += 360;
		}
		if (keycode == DOWN)
			move_back(e);
	}
	return (0);
}
