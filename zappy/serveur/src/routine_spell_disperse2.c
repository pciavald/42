/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_spell_disperse2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:26:39 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 11:27:11 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	disperse_linemate(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][1];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->linemate += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].linemate -= 1;
	}
}

void	disperse_deraumere(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][2];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->deraumere += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].deraumere -= 1;
	}
}

void	disperse_sibur(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][3];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->sibur += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].sibur -= 1;
	}
}
