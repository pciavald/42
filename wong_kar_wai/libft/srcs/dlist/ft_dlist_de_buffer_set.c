/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_de_buffer_set.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:24:58 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:24:59 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_dlist_de.h"

void	ft_dlist_de_buffer_set(
	t_de_dlist *head, size_t size, size_t num, char *buf)
{
	while (num--)
	{
		ft_dlist_de_push_front((t_dlist *)buf, head);
		buf += size;
	}
}
