/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:05:01 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:13:33 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "game_2048.h"

void	victory(t_data *data);
void	error(char *err, char *arg, int quit);
void	game(t_data *data);
int		input_is_valid(int *game, t_data *data);
void	push_lines(int *game, t_data *data);

#endif
