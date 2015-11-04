/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:17:21 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:17:22 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist_queue.h"

void		ft_slist_queue_init(t_slist_queue *head, int type)
{
	head->type = type;
	head->size = 0;
	head->front.next = &(head->queue);
	head->queue.next = &(head->front);
}

void		ft_slist_queue_push(t_slist *item, t_slist_queue *head)
{
	head->size++;
	ft_slist_add(head->front.next, item, &(head->front));
}

t_slist		*ft_list_queue_pop(t_slist_queue *head)
{
	t_slist	*ret;

	head->size--;
	ret = head->queue.next;
	ft_slist_remove(&(head->queue), ret->next);
	return (ret);
}
