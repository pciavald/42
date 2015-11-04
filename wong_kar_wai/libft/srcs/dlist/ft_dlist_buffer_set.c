/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_buffer_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:48:21 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 16:48:22 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_dlist_de.h"
#include "ft_dlist_buffer.h"
#include <stdlib.h>

void		ft_dlist_de_init_buf(
	t_buf_dlist *buf, size_t size, size_t num, int type)
{
	buf->malloc_done = 0;
	buf->structure_size = size;
	buf->structure_number = num;
	ft_dlist_de_init_head(&(buf->head), type);
	buf->malloc_adress = NULL;
}

void		ft_dlist_buffer_malloc(t_buf_dlist *buf)
{
	void	**ptr;

	ptr = malloc(
		sizeof(void *) + buf->structure_size * buf->structure_number);
	*ptr = buf->malloc_adress;
	buf->malloc_adress = ptr;
	ptr++;
	ft_dlist_de_buffer_set(
		&(buf->head),
		buf->structure_size,
		buf->structure_number,
		(char *)ptr);
}

t_dlist		*ft_dlist_de_buf_pop(t_buf_dlist *buf)
{
	if (buf->head.size == 0)
		ft_dlist_buffer_malloc(buf);
	return (ft_dlist_de_pop_front(&(buf->head)));
}

void		ft_dlist_de_buf_push(t_dlist *item, t_buf_dlist *buffer)
{
	ft_dlist_de_push_front(item, &(buffer->head));
}
