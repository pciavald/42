/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:04:42 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:16:45 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	neighbour_check(int *game, t_data *data)
{
	int		index;

	index = 0;
	while (index < BSIZE)
	{
		if (index % GSIZE != GSIZE - 1)
			if (game[index] == game[index + 1])
				return (0);
		if (index / GSIZE != GSIZE - 1)
			if (game[index] == game[index + GSIZE])
				return (0);
		index++;
	}
	return (1);
}

static int	liberty(int *game, t_data *data)
{
	int		locus;
	int		liberty;

	locus = 0;
	liberty = 0;
	while (locus < BSIZE)
	{
		if (!game[locus])
			liberty++;
		locus++;
	}
	return (liberty);
}

static int	random_new(int *game, t_data *data)
{
	int	nth;
	int	index;
	int	lib;

	lib = liberty(game, data);
	nth = rand() % lib;
	index = 0;
	while (game[index])
		index++;
	while (nth--)
	{
		index++;
		while (game[index])
			index++;
	}
	game[index] = (rand() % 25 == 24) ? 2 : 1;
	return (lib - 1);
}

static void	rotate(int *game, t_data *data)
{
	int		token;
	int		result[BSIZE];

	token = -1;
	while (++token < BSIZE)
		result[(GSIZE - 1 - token / GSIZE) \
			+ GSIZE * (token % GSIZE)] = game[token];
	ft_memcpy(game, result, sizeof(result));
}

void		game(t_data *data)
{
	int		rotation;

	rotation = 0;
	if (data->input >= 0 && data->input <= 3)
	{
		while (rotation++ < data->input)
			rotate(data->game, data);
		if (input_is_valid(data->game, data))
		{
			data->redraw = 1;
			push_lines(data->game, data);
			victory(data);
			if (!random_new(data->game, data))
				data->game_lost = neighbour_check(data->game, data);
		}
		while (rotation++ <= 4)
			rotate(data->game, data);
		data->input = -1;
	}
}
