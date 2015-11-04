/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 15:15:16 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/02 15:15:18 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	input(t_data *data)
{
	int	ch;

	ch = getch();
	if (ch == KEY_RIGHT)
		data->input = 2;
	if (ch == KEY_DOWN)
		data->input = 1;
	if (ch == KEY_LEFT)
		data->input = 0;
	if (ch == KEY_UP)
		data->input = 3;
	if (ch == 27)
		data->input = -2;
	if (ch == KEY_RESIZE)
		data->resize = 1;
}
