/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_de_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:25:28 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:25:29 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist_de.h"

void	ft_dlist_de_push_front(t_dlist *item, t_de_dlist *head)
{
	head->size++;
	ft_dlist_add(item, &(head->ends), head->ends.next);
}

void	ft_dlist_de_push_back(t_dlist *item, t_de_dlist *head)
{
	head->size++;
	ft_dlist_add(item, head->ends.prev, &(head->ends));
}
