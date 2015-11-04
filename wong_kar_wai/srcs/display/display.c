/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 02:14:43 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 22:43:20 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	print_string(WINDOW *win, char *str, int x, int y)
{
	int		nx;
	int		ny;

	nx = 1;
	ny = 0;
	attron(A_BOLD);
	while (*str)
	{
		if (*str == '\n')
		{
			nx = 0;
			ny++;
		}
		mvwprintw(win, y + ny, x + nx, "%c", *str);
		nx++;
		str++;
	}
	wrefresh(win);
	refresh();
}

static void	clear_tile(WINDOW *win)
{
	int		x;
	int		y;
	int		i;
	int		j;

	getmaxyx(win, y, x);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			mvwprintw(win, i, j, " ");
			j++;
		}
		i++;
	}
	wrefresh(win);
	refresh();
}

static void	print_tile(WINDOW *win, int index, t_data *data)
{
	t_font		*font;
	t_canvas	*can;
	int			xy[2];
	char		*line;
	int			n;

	can = &(data->canvas);
	font = &(can->font);
	clear_tile(win);
	if (data->game[index] != 0)
	{
		line = ft_strdup(font->img[data->game[index] - 1]);
		n = ft_strchr(line, '\n') - line;
		line[n] = '\0';
		xy[0] = (can->tile_width - ft_strlen(line)) / 2 - 1;
		xy[1] = (can->tile_height - font->img_height) / 2;
		ft_strdel(&line);
		print_string(win, font->img[data->game[index] - 1], xy[0], xy[1]);
	}
	wrefresh(win);
	refresh();
}

static void	color_window(WINDOW *win, int val, t_data *data)
{
	(void)data;
	if (val == 0)
		wbkgd(win, COLOR_PAIR(13));
	else
		wbkgd(win, COLOR_PAIR(val));
	wrefresh(win);
	refresh();
}

void		display(t_data *data)
{
	int		index;
	WINDOW	*win;

	if (data->redraw == 1)
	{
		index = 0;
		if (data->victory)
			mvprintw(1, 1, "VICTOIRE");
		mvprintw(data->vert_offset, data->hori_offset,
			"Score : %i", data->score);
		while (index < BSIZE)
		{
			win = data->canvas.windows[index];
			color_window(win, data->game[index], data);
			print_tile(win, index, data);
			index++;
		}
	}
	data->redraw = 0;
}
