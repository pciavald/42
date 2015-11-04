/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:25:24 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:25:25 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

t_dlist		*ft_dlist_malloc(size_t size)
{
	t_dlist	*ret;

	if (!(ret = (t_dlist*)malloc(sizeof(t_dlist) + size)))
		return (NULL);
	return (ret);
}
