/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_buffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:44:39 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 16:44:40 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_BUFFER_H
# define FT_DLIST_BUFFER_H
# include "ft_dlist.h"
# include "ft_dlist_de.h"

typedef struct	s_buf_dlist
{
	int			malloc_done;
	size_t		structure_number;
	size_t		structure_size;
	t_de_dlist	head;
	void		*malloc_adress;
}				t_buf_dlist;

void			ft_alloc_new_dlist_buffer(t_buf_dlist *buffer);
t_dlist			*ft_dlist_de_buf_pop(t_buf_dlist *buffer);
void			ft_dlist_de_buf_push(t_dlist *item, t_buf_dlist *buffer);
void			ft_dlist_de_init_buf(
	t_buf_dlist *buf, size_t size, size_t num, int type);
#endif
