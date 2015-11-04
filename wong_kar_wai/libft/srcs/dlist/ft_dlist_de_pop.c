/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_de_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:25:26 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:25:27 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist_de.h"

t_dlist		*ft_dlist_de_pop_front(t_de_dlist *head)
{
	t_dlist	*pop;

	if (head->size == 0)
		return (NULL);
	pop = head->ends.next;
	ft_dlist_remove(pop);
	head->size--;
	return (pop);
}

t_dlist		*ft_dlist_de_pop_back(t_de_dlist *head)
{
	t_dlist	*pop;

	if (head->size == 0)
		return (NULL);
	pop = head->ends.prev;
	ft_dlist_remove(pop);
	head->size--;
	return (pop);
}
