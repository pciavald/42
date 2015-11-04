/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:53:28 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/16 20:19:56 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	(void)l_b;
	if (*l_a && (*l_a)->next)
	{
		tmp = (*l_a)->next;
		(*l_a)->next = tmp->next;
		tmp->next = (*l_a);
		(*l_a) = tmp;
		display("sa ", args);
	}
}

void	sb(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	(void)l_a;
	if (*l_b && (*l_b)->next)
	{
		tmp = (*l_b)->next;
		(*l_b)->next = tmp->next;
		tmp->next = (*l_b);
		(*l_b) = tmp;
		display("sb ", args);
	}
}

void	ss(t_num **l_a, t_num **l_b, int args)
{
	sa(l_a, NULL, args);
	sb(NULL, l_b, args);
	display("ss ", args);
}
