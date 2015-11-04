/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:51:14 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/03 16:51:15 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_page(int position, int item_per_page)
{
	return (position / item_per_page);
}

void	move_to(t_data *data, t_sdlst *current, int position)
{
	data->items.old = data->items.current;
	data->items.current.item = current;
	data->items.old.item->is_current = 0;
	data->items.current.item->is_current = 1;
	data->items.current.position = position;
	if (get_page(position, data->interface.item_per_page) != data->page.number)
		reload_page(data);
	else
		data->items.draw = 1;
}

t_sdlst	*forward_list(t_sdlst *start, int number)
{
	while (number--)
		start = start->next;
	return (start);
}

t_sdlst	*backward_list(t_sdlst *start, int number)
{
	while (number--)
		start = start->prev;
	return (start);
}
