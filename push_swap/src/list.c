/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:51:40 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:50:08 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*make_node(int n)
{
	t_num	*node;

	node = (t_num *)malloc(sizeof(t_num));
	node->n = n;
	node->next = NULL;
	return (node);
}

t_num	*make_list(char **list, int argc)
{
	t_num		*l_a;
	t_num		*node;
	t_num		*last;
	int			i;

	last = NULL;
	i = 0;
	while (i < argc)
	{
		if (last)
		{
			node = make_node(ft_atoi(list[i]));
			last->next = node;
			last = node;
		}
		else
		{
			l_a = make_node(ft_atoi(list[i]));
			last = l_a;
		}
		i++;
	}
	return (l_a);
}

t_num	*last(t_num *list)
{
	if (list)
	{
		while (list->next)
			list = list->next;
	}
	return (list);
}
