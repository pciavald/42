/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:24:16 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:14:35 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <ncurses.h>

typedef struct	s_font
{
	int			img_width;
	int			img_height;
	char		*img_type;
	char		img[11][2048];
}				t_font;

typedef struct	s_canvas
{
	int			tile_width;
	int			tile_height;
	WINDOW		*windows[100];
	t_font		font;
}				t_canvas;

typedef struct	s_data
{
	int			size;
	int			game_lost;
	int			redraw;
	int			input;
	int			game[100];
	t_canvas	canvas;
	int			resize;
	int			vert_offset;
	int			hori_offset;
	int			score;
	int			victory;
}				t_data;

#endif
