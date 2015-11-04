/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:15:53 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:15:54 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"
#include "ft_slist_stack.h"

void	ft_slist_stack_init(t_slist_stack *head, int type)
{
	head->type = type;
	head->size = 0;
	head->stack.next = NULL;
}

void	ft_slist_stack_push(t_slist *item, t_slist_stack *head)
{
	head->size++;
	ft_slist_add(&(head->stack), item, head->stack.next);
}

t_slist	*ft_slist_stack_pop(t_slist_stack *head)
{
	t_slist	*ret;

	head->size--;
	ret = head->stack.next;
	ft_slist_remove(&(head->stack), ret->next);
	return (ret);
}
