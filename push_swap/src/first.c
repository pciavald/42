/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 20:08:01 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 23:02:14 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	if (*l_b)
	{
		tmp = (*l_b)->next;
		(*l_b)->next = *l_a;
		*l_a = *l_b;
		*l_b = tmp;
		display("pa ", args);
	}
}

void	pb(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	if (*l_a)
	{
		tmp = (*l_a)->next;
		(*l_a)->next = *l_b;
		*l_b = *l_a;
		*l_a = tmp;
		display("pb ", args);
	}
}
