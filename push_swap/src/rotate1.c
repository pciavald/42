/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 20:21:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/17 10:25:47 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	(void)l_b;
	tmp = *l_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *l_a;
	*l_a = (*l_a)->next;
	tmp->next->next = NULL;
	display("ra ", args);
}

void	rb(t_num **l_a, t_num **l_b, int args)
{
	t_num	*tmp;

	(void)l_a;
	tmp = *l_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *l_b;
	*l_b = (*l_b)->next;
	tmp->next->next = NULL;
	display("rb ", args);
}

void	rr(t_num **l_a, t_num **l_b, int args)
{
	ra(l_a, NULL, args);
	rb(NULL, l_b, args);
}
