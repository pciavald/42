/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spell_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 03:34:37 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/26 20:36:38 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

static void		row0(int **tab)
{
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = 0;
	tab[0][3] = 0;
	tab[0][4] = 0;
	tab[0][5] = 0;
	tab[0][6] = 0;
	tab[1][0] = 2;
	tab[1][1] = 1;
	tab[1][2] = 1;
	tab[1][3] = 1;
	tab[1][4] = 0;
	tab[1][5] = 0;
	tab[1][6] = 0;
	tab[2][0] = 2;
	tab[2][1] = 2;
	tab[2][2] = 0;
	tab[2][3] = 1;
	tab[2][4] = 0;
	tab[2][5] = 2;
	tab[2][6] = 0;
}

static void		row1(int **tab)
{
	tab[3][0] = 4;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = 2;
	tab[3][4] = 0;
	tab[3][5] = 1;
	tab[3][6] = 0;
	tab[4][0] = 4;
	tab[4][1] = 1;
	tab[4][2] = 2;
	tab[4][3] = 1;
	tab[4][4] = 3;
	tab[4][5] = 0;
	tab[4][6] = 0;
	tab[5][0] = 6;
	tab[5][1] = 1;
	tab[5][2] = 2;
	tab[5][3] = 3;
	tab[5][4] = 0;
	tab[5][5] = 1;
	tab[5][6] = 0;
}

static void		row2(int **tab)
{
	tab[6][0] = 6;
	tab[6][1] = 2;
	tab[6][2] = 2;
	tab[6][3] = 2;
	tab[6][4] = 2;
	tab[6][5] = 2;
	tab[6][6] = 1;
}

void			init_spell_tab(t_data *data)
{
	int		i;

	data->spell_tab = (int**)malloc(sizeof(int*) * 7);
	i = -1;
	while (++i < 7)
	{
		data->spell_tab[i] = (int*)malloc(sizeof(int) * 7);
	}
	row0(data->spell_tab);
	row1(data->spell_tab);
	row2(data->spell_tab);
}
