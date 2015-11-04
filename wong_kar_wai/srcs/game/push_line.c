/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:46:43 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 11:46:45 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	add_score(int ln2, t_data *data)
{
	int		result;

	result = 1;
	while (ln2--)
	{
		result *= 2;
	}
	data->score += result;
}

static int	get_next_value(int *game, int head, t_data *data)
{
	int		ret;

	ret = 0;
	while (head < GSIZE && game[head] == 0)
		head++;
	if (head != GSIZE)
	{
		ret = game[head];
		game[head] = 0;
	}
	return (ret);
}

static void	push_line(int *game, t_data *data)
{
	int		stack;
	int		value;

	stack = 0;
	while (stack < GSIZE)
	{
		value = get_next_value(game, stack + 1, data);
		if (value == 0)
			return ;
		else if (game[stack] == value)
		{
			game[stack] += 1;
			add_score(game[stack], data);
			stack++;
		}
		else if (game[stack] == 0)
			game[stack] = value;
		else if (game[stack] != value)
		{
			stack++;
			game[stack] = value;
		}
	}
}

void		push_lines(int *game, t_data *data)
{
	int		y;

	y = 0;
	while (y < GSIZE)
		push_line(game + GSIZE * y++, data);
}
