/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_circ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:17:35 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:17:36 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"
#include "ft_slist_circ.h"

void		ft_slist_circ_init(t_slist_circ *head, int type)
{
	head->type = type;
	head->size = 0;
	head->first.next = NULL;
	head->last.next = NULL;
}

void		ft_slist_circ_stack(t_slist *item, t_slist_circ *head)
{
	head->size++;
	if (head->last.next == NULL)
	{
		head->last.next = item;
		head->first.next = item;
	}
	ft_slist_add(head->last.next, item, head->first.next);
	head->first.next = item;
}

void		ft_slist_circ_queue(t_slist *item, t_slist_circ *head)
{
	head->size++;
	if (head->last.next == NULL)
	{
		head->last.next = item;
		head->first.next = item;
	}
	ft_slist_add(head->last.next, item, head->first.next);
	head->last.next = item;
}

t_slist		*ft_list_circ_pop(t_slist_circ *head)
{
	t_slist	*ret;

	head->size--;
	ret = head->first.next;
	if (head->size == 0)
	{
		head->last.next = NULL;
		head->first.next = NULL;
	}
	else
		ft_slist_remove(head->last.next, ret->next);
	return (ret);
}
