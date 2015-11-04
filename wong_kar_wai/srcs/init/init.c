/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:10:39 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 21:18:57 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	srand(time(NULL));
	load_images(&data->canvas.font);
	init_signals();
	data->redraw = 1;
}
