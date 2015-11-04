/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 20:40:23 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 20:40:25 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

inline void	ft_slist_add(t_slist *prev, t_slist *new, t_slist *next)
{
	new->next = next;
	prev->next = new;
}
