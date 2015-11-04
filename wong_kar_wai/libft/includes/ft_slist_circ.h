/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_circ.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:17:52 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:17:53 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLIST_CIRC_H
# define FT_SLIST_CIRC_H
# include "ft_slist.h"
# include <stddef.h>

typedef struct	s_slist_circ
{
	int			type;
	size_t		size;
	t_slist		first;
	t_slist		last;
}				t_slist_circ;

void			ft_slist_circ_init(t_slist_circ *head, int type);
void			ft_slist_circ_stack(t_slist *item, t_slist_circ *head);
void			ft_slist_circ_queue(t_slist *item, t_slist_circ *head);
t_slist			*ft_list_circ_pop(t_slist_circ *head);
#endif
