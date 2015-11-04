/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:19:03 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/20 03:09:46 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	is_prevp(t_data *data, char *key)
{
	t_word	*tmp;
	int		a;
	int		b;
	int		c;

	if (key[0] == 27 && key[1] == '[' && key[2] == '5' && key[3] == '~')
	{
		a = data->current;
		b = data->maxwpp;
		c = data->tpage;
		tmp = curword(data);
		tmp->und = 0;
		data->current = (a - (a % b) + (c - 1) * b) % (b * c);
		tmp = curword(data);
		tmp->und = 1;
	}
}

void	is_nextp(t_data *data, char *key)
{
	t_word	*tmp;
	int		a;
	int		b;
	int		c;

	if (key[0] == 27 && key[1] == '[' && key[2] == '6' && key[3] == '~')
	{
		a = data->current;
		b = data->maxwpp;
		c = data->tpage;
		tmp = curword(data);
		tmp->und = 0;
		data->current = (a - (a % b) + (c + 1) * b) % (b * c);
		tmp = curword(data);
		tmp->und = 1;
	}
}

void	is_minus(t_data *data, char *key)
{
	if (key[0] == '-' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		if (data->colwid > 5)
			data->colwid--;
	}
}

void	is_plus(t_data *data, char *key)
{
	if (key[0] == '+' && key[1] == 0 && key[2] == 0 && key[3] == 0)
		data->colwid++;
}
