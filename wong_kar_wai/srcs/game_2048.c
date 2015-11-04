/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:56:41 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 18:56:07 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	resize(t_data *data)
{
	endwin();
	init_ncurses();
	init_canvas(data);
	clear();
	data->redraw = 1;
	data->resize = 0;
}

static int	win_value(void)
{
	if (WIN_VALUE % 2)
	{
		ft_putendl_fd("Please modify WIN_VALUE in game_2048.h", 2);
		ft_putendl_fd("Value must be a power of 2.", 2);
		return (-1);
	}
	return (0);
}

static void	game_manager(t_data *data)
{
	//load_menu
	data->size = 10;
	init_ncurses();
	init_game(data->game, data);
	init_canvas(data);
	while (data->game_lost == 0 && data->input != -2)
	{
		if (data->resize)
			resize(data);
		display(data);
		input(data);
		game(data);
	}
}

int			main(int argc, char **argv)
{
	t_data data;

	g_data = &data;
	(void)argc;
	(void)argv;
	if (win_value())
		return (-1);
	init(&data);
	game_manager(&data);
	endwin();
	return (0);
}
