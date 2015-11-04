/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:46:24 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 11:46:26 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	return_next_value(int *game, int head, t_data *data)
{
	int		ret;

	ret = 0;
	while (head < GSIZE && game[head] == 0)
		head++;
	if (head != GSIZE)
		ret = game[head];
	return (ret);
}

static int	line_is_valid(int *game, t_data *data)
{
	int		stack;

	stack = 0;
	while (stack < GSIZE)
	{
		if (game[stack] == 0)
			return (return_next_value(game, stack + 1, data));
		else if (game[stack] == return_next_value(game, stack + 1, data))
			return (1);
		stack++;
	}
	return (0);
}

int			input_is_valid(int *game, t_data *data)
{
	int		y;
	int		ret;

	y = 0;
	ret = 0;
	while (y < GSIZE)
		ret += line_is_valid(game + GSIZE * y++, data);
	return (ret);
}
