/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:15:24 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "header_wolf3d.h"

static int		hor_intersect(t_env *e, t_dot *a, double angle)
{
	t_dot		delta;

	delta.y = GRID;
	if (angle >= 0 && angle < 180)
	{
		a->y = (e->p.y / GRID) * GRID - 1;
		delta.y = delta.y * -1;
	}
	else if (angle >= 180 && angle <= 359)
		a->y = (e->p.y / GRID) * GRID + GRID;
	a->x = e->p.x + ((e->p.y - a->y) / e->tan[(int)(angle * 10)]);
	delta.x = -delta.y / e->tan[(int)(angle * 10)];
	while (a->y < e->map_size.y * GRID && a->y >= 0
			&& a->x < e->map_size.x * GRID && a->x >= 0)
	{
		if (e->map[a->y / GRID][a->x / GRID] == 1)
			return (1);
		a->x = a->x + delta.x;
		a->y = a->y + delta.y;
	}
	return (0);
}

static int		ver_intersect(t_env *e, t_dot *b, double angle)
{
	t_dot		delta;

	delta.x = GRID;
	if (angle > 270 || angle <= 90)
		b->x = (e->p.x / GRID) * GRID + GRID;
	else if (angle > 90 && angle <= 270)
	{
		delta.x = delta.x * -1;
		b->x = (e->p.x / GRID) * GRID - 1;
	}
	b->y = e->p.y + ((e->p.x - b->x) * e->tan[(int)(angle * 10)]);
	delta.y = -delta.x * e->tan[(int)(angle * 10)];
	while (b->y < e->map_size.y * GRID && b->y >= 0
			&& b->x < e->map_size.x * GRID && b->x >= 0)
	{
		if (e->map[b->y / GRID][b->x / GRID] == 1)
			return (1);
		b->x = b->x + delta.x;
		b->y = b->y + delta.y;
	}
	return (0);
}

static double	find_distance(t_env *e, t_dot *z, double angle_dist)
{
	double		pz;

	pz = sqrt(ft_square(e->p.x - z->x) + ft_square(e->p.y - z->y));
	return (ft_abs(pz * e->cos[(int)(angle_dist * 10)]));
}

double			find_height(t_env *e, double angle, double angle_dist)
{
	t_dot		a;
	t_dot		b;
	double		pa;
	double		pb;

	pa = 1000000000;
	pb = 1000000000;
	if (hor_intersect(e, &a, angle))
		pa = find_distance(e, &a, angle_dist);
	if (ver_intersect(e, &b, angle))
		pb = find_distance(e, &b, angle_dist);
	if (pa <= pb && pa != 1000000000)
	{
		e->color = check_color(angle, 1, 0);
		return (e->disto / pa);
	}
	else if (pb < pa && pb != 1000000000)
	{
		e->color = check_color(angle, 0, 1);
		return (e->disto / pb);
	}
	return (0);
}
