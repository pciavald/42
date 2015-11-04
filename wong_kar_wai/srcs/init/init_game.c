/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:19:12 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:22:55 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	init_game(int *game, t_data *data)
{
	int	first;
	int	value;
	int	second;

	first = rand() % BSIZE;
	while (first == (second = rand() % BSIZE))
		;
	value = (rand() % 25 == 24) ? 2 : 1;
	game[first] = value;
	value = (rand() % 25 == 24) ? 2 : 1;
	game[second] = value;
}
