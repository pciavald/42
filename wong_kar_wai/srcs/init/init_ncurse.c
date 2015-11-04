/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:50:09 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 22:50:10 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	init_ncurses(void)
{
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	curs_set(0);
	noecho();
	init_colors();
}
