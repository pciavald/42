/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:05:11 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 19:28:43 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "game_2048.h"

# include <signal.h>
# include <stdlib.h>
# include <time.h>

void	init(t_data *data);
void	init_ncurses(void);
void	init_canvas(t_data *data);
void	init_colors(void);
void	init_game(int *game, t_data *data);
void	init_signals(void);
void	load_images(t_font *font);

#endif
