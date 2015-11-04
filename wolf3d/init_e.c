/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:18:10 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_wolf3d.h"

static void		get_map(t_env *e, int i, int j)
{
	int			map[12][12] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,1,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,0,0,0,0,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,1,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};

	e->map = (int **)malloc(sizeof(int *) * 12);
	while (++i < 12)
	{
		e->map[i] = (int *)malloc(sizeof(int) * 12);
		j = -1;
		while (++j < 12)
			e->map[i][j] = map[i][j];
	}
}

static void		init_cos_tan(t_env *e)
{
	int			i;
	double		rad;

	i = 0;
	e->cos = (double *)malloc(sizeof(double) * 3600);
	e->sin = (double *)malloc(sizeof(double) * 3600);
	e->tan = (double *)malloc(sizeof(double) * 3600);
	while (i < 3600)
	{
		rad = (((double)i / 10) * 2.0 * 3.14159265359) / 360;
		e->cos[i] = cos(rad);
		e->sin[i] = -sin(rad);
		e->tan[i] = tan(rad);
		i++;
	}
}

void			init_p(t_env *e)
{
	t_dot		i;

	i.x = 10 * GRID + (GRID / 2);
	i.y = 5 * GRID + (GRID / 2);
	i.a = START_ANGLE;
	e->p = i;
}

void			init_e(t_env *e)
{
	init_cos_tan(e);
	get_map(e, -1, -1);
	e->map_size.x = 12;
	e->map_size.y = 12;
	init_p(e);
	e->fov = 120;
	e->speed = 0.1;
	e->disto = (double)GRID * ((double)(WIN_X / 2) / e->tan[(e->fov / 2) * 10]);
}

