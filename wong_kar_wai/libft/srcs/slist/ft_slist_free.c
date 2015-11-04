/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 23:12:10 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 23:12:11 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"
#include "ft_slist_stack.h"
#include "ft_slist_free.h"
#include <stdlib.h>

static void	ft_slist_free_array_push(
	t_slist_stack *stack, size_t size, size_t num, char *buf)
{
	while (num--)
	{
		ft_slist_stack_push((t_slist *)buf, stack);
		buf += size;
	}
}

static void	ft_slist_free_malloc(t_slist_free *buf)
{
	t_slist	*ptr;
	t_slist	*array;

	ptr = malloc(
		sizeof(t_slist) + buf->structure_size * buf->structure_number);
	ft_slist_stack_push(ptr, &(buf->alloc_adress));
	buf->malloc_done++;
	array = FT_SL_DATA(t_slist, ptr);
	ft_slist_free_array_push(
		&(buf->stack),
		buf->structure_size,
		buf->structure_number,
		(char *)array);
}

void		ft_slist_free_init(
	t_slist_free *buf, size_t size, size_t num, int type)
{
	buf->malloc_done = 0;
	buf->structure_size = size;
	buf->structure_number = num;
	ft_slist_stack_init(&(buf->stack), type);
	ft_slist_stack_init(&(buf->alloc_adress), type);
}

t_slist		*ft_slist_free_pop(t_slist_free *buf)
{
	if (buf->stack.size == 0)
		ft_slist_free_malloc(buf);
	return (ft_slist_stack_pop(&(buf->stack)));
}

void		ft_slist_free_push(t_slist *item, t_slist_free *buf)
{
	ft_slist_stack_push(item, &(buf->stack));
}
