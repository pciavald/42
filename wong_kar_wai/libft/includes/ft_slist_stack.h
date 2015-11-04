/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_stack.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 20:57:08 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 20:57:09 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLIST_STACK_H
# define FT_SLIST_STACK_H
# include "ft_slist.h"
# include <stddef.h>

typedef struct	s_slist_stack
{
	int			type;
	size_t		size;
	t_slist		stack;
}				t_slist_stack;

void			ft_slist_stack_init(t_slist_stack *head, int type);
void			ft_slist_stack_push(t_slist *item, t_slist_stack *head);
t_slist			*ft_slist_stack_pop(t_slist_stack *head);

#endif
