/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:46:38 by pciavald          #+#    #+#             */
/*   Updated: 2015/03/01 21:17:17 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	create_colors(void)
{
	init_color(0, 678, 615, 556);
	init_color(1, 917, 870, 819);
	init_color(2, 913, 854, 733);
	init_color(3, 936, 635, 384);
	init_color(4, 952, 509, 297);
	init_color(5, 956, 395, 282);
	init_color(6, 956, 270, 148);
	init_color(7, 913, 784, 344);
	init_color(8, 913, 768, 274);
	init_color(9, 913, 752, 207);
	init_color(40, 968, 956, 932);
	init_color(41, 392, 356, 321);
	init_color(43, 756, 701, 642);
}

void		init_colors(void)
{
	start_color();
	create_colors();
	init_pair(0, 40, 0);
	init_pair(1, 41, 1);
	init_pair(2, 41, 2);
	init_pair(3, 40, 3);
	init_pair(4, 40, 4);
	init_pair(5, 40, 5);
	init_pair(6, 40, 6);
	init_pair(7, 40, 7);
	init_pair(8, 40, 8);
	init_pair(9, 40, 9);
	init_pair(10, 40, 10);
	init_pair(11, 40, 11);
	init_pair(12, 42, 12);
	init_pair(13, 42, 43);
}
