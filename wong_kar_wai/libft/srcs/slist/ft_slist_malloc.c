/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 20:39:05 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 20:39:08 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"
#include <stdlib.h>

inline t_slist	*ft_slist_malloc(size_t size)
{
	t_slist		*ret;

	if (!(ret = (t_slist*)malloc(sizeof(t_slist) + size)))
		return (NULL);
	return (ret);
}
