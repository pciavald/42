/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isarrow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:17:13 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/20 03:09:42 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		is_left(t_data *data, char *key)
{
	t_word	*tmp;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'D' && key[3] == 0)
	{
		if (data->current % data->maxwpp > data->maxl && data->maxc > 1)
		{
			tmp = curword(data);
			tmp->und = 0;
			data->current = data->current - data->maxl;
			tmp = curword(data);
			tmp->und = 1;
		}
	}
}

void		is_right(t_data *data, char *key)
{
	t_word	*tmp;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'C' && key[3] == 0)
	{
		if (data->current % data->maxwpp < data->maxl * (data->maxc - 1)
			&& data->maxc > 1)
		{
			tmp = curword(data);
			tmp->und = 0;
			data->current = data->current + data->maxl;
			if (data->current > data->size - 1)
				data->current = data->size - 1;
			tmp = curword(data);
			tmp->und = 1;
		}
	}
}

void		is_up(t_data *data, char *key)
{
	t_word	*tmp;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'A' && key[3] == 0)
	{
		tmp = curword(data);
		tmp->und = 0;
		tmp->prev->und = 1;
		if (data->current)
			data->current--;
		else
			data->current = data->size - 1;
	}
}

void		is_down(t_data *data, char *key)
{
	t_word	*tmp;

	if (key[0] == 27 && key[1] == '[' && key[2] == 'B' && key[3] == 0)
	{
		tmp = curword(data);
		tmp->und = 0;
		tmp->next->und = 1;
		if (data->current < data->size - 1)
			data->current++;
		else
			data->current = 0;
	}
}
