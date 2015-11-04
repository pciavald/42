/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 20:34:42 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/17 10:29:45 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;
	t_num	*last;

	(void)l_b;
	tmp = *l_a;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *l_a;
		*l_a = last;
		display("rra ", args);
	}
}

void	rrb(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;
	t_num	*last;

	(void)l_a;
	tmp = *l_b;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *l_b;
		*l_b = last;
		display("rrb ", args);
	}
}

void	rrr(t_num **l_a, t_num **l_b, int args)
{
	rra(l_a, l_b, args);
	rra(l_a, l_b, args);
}
