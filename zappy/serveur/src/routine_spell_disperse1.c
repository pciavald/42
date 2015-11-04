/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_spell_disperse1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:23:41 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/26 15:50:58 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <time.h>

static void		disperse_mendiane(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][4];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->mendiane += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].mendiane -= 1;
	}
}

static void		disperse_phiras(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][5];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->phiras += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].phiras -= 1;
	}
}

static void		disperse_thystame(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][6];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->thystame += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].thystame -= 1;
	}
}

void			disperse(t_data *data, t_spell *spell)
{
	srand(time(NULL));
	disperse_linemate(data, spell);
	disperse_deraumere(data, spell);
	disperse_sibur(data, spell);
	disperse_mendiane(data, spell);
	disperse_phiras(data, spell);
	disperse_thystame(data, spell);
	gui_broadcast(data, gui_bct, get_square(data, spell->x, spell->y));
}
