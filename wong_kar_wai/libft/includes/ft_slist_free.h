/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_free.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:18:33 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:18:34 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLIST_FREE_H
# define FT_SLIST_FREE_H
# include "ft_slist.h"
# include "ft_slist_stack.h"
# define FT_SL_SIZE(type) (sizeof(t_slist) + sizeof(type))

typedef struct		s_slist_free
{
	size_t			malloc_done;
	size_t			structure_number;
	size_t			structure_size;
	t_slist_stack	stack;
	t_slist_stack	alloc_adress;
}					t_slist_free;

void				ft_slist_free_init(
	t_slist_free *buf, size_t size, size_t num, int type);
t_slist				*ft_slist_free_pop(t_slist_free *buf);
void				ft_slist_free_push(t_slist *item, t_slist_free *buf);

#endif
