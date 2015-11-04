/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:14:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_wolf3d.h"

static void		draw_pixel(void *imlx, int x, int y, int color)
{
	char		*img;
	int			bpp;
	int			size_line;
	int			endian;
	int			index;

	img = mlx_get_data_addr(imlx, &bpp, &size_line, &endian);
	index = y * size_line + x * bpp / 8;
	if (index >= 0 && index < (WIN_Y * size_line + WIN_X * bpp / 8))
	{
		img[index] = color;
		img[index + 1] = color;
		img[index + 2] = color;
	}
}

static void		draw_ray(void *imlx, int ray_size, int ray_x, int color)
{
	int			y;
	int			y_max;
	int			i;

	y = WIN_Y / 2 - ray_size / 2;
	y_max = WIN_Y / 2 + ray_size / 2;
	i = -1;
	while (++i <= y)
		draw_pixel(imlx, ray_x, i, 250);
	while (y <= y_max)
	{
		draw_pixel(imlx, ray_x, y, color);
		y++;
	}
	while (++y_max <= WIN_X)
		draw_pixel(imlx, ray_x, y_max, 0);
}

int				draw_img(t_env *e)
{
	double		angle;
	double		inc;
	double		ray_pos;
	double		angle_dist;
	int			ray_size;

	angle = e->p.a - 30.0;
	inc = 60.0 / WIN_X;
	ray_pos = WIN_X;
	angle_dist = -30;
	while (ray_pos > 0)
	{
		if (angle > 360)
			angle = angle - 360;
		else if (angle < 0)
			angle = angle + 360;
		ray_size = find_height(e, angle, ft_abs(angle_dist));
		if (ray_size > 0)
			draw_ray(e->imlx, ray_size, ray_pos, e->color);
		ray_pos--;
		angle_dist += inc;
		angle += inc;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->imlx, 0, 0);
	return (0);
}
