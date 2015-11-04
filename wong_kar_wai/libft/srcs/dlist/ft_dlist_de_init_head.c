/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_de_init_head.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:42:24 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:42:30 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist_de.h"

void		ft_dlist_de_init_head(t_de_dlist *head, int type)
{
	head->type = type;
	head->size = 0;
	head->ends.next = &(head->ends);
	head->ends.prev = &(head->ends);
}
