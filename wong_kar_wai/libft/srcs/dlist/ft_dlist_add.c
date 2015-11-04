/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:24:56 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:24:57 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_add(t_dlist *new, t_dlist *prev, t_dlist *next)
{
	new->next = next;
	next->prev = new;
	new->prev = prev;
	prev->next = new;
}
