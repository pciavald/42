/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:19:24 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:20:26 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init_windows(t_data *data)
{
	int		xitem;
	int		yitem;

	yitem = 0;
	while (yitem < GSIZE)
	{
		xitem = 0;
		while (xitem < GSIZE)
		{
			data->canvas.windows[yitem * GSIZE + xitem] =
				newwin(data->canvas.tile_height,
						data->canvas.tile_width,
						data->vert_offset + 1 + yitem *
						(data->canvas.tile_height + 1),
						data->hori_offset + 1 + xitem *
						(data->canvas.tile_width + 2));
			xitem++;
		}
		yitem++;
	}
}

void		init_canvas(t_data *data)
{
	int		row;
	int		col;
	int		width;
	int		height;
	int		size;

	getmaxyx(stdscr, row, col);
	width = ((col - 2) / GSIZE) - 2;
	height = ((row - 2) / GSIZE) - 1;
	height *= 23;
	width *= 10;
	size = (height > width) ? width : height;
	data->canvas.tile_height = size / 23;
	data->vert_offset = (row - (data->canvas.tile_height + 1) * GSIZE) / 2;
	data->canvas.tile_width = size / 10;
	data->hori_offset = (col - (data->canvas.tile_width + 2) * GSIZE) / 2;
	init_windows(data);
	(void)data;
}
