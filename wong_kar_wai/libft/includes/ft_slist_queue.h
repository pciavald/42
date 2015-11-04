/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_queue.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 21:17:45 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/22 21:17:46 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** items are added to front->next, and taken from queue->next.
** next points from queue to front
*/

#ifndef FT_SLIST_QUEUE_H
# define FT_SLIST_QUEUE_H
# include "ft_slist.h"
# include <stddef.h>

typedef struct	s_slist_queue
{
	int			type;
	size_t		size;
	t_slist		front;
	t_slist		queue;
}				t_slist_queue;

void			ft_slist_queue_init(t_slist_queue *head, int type);
void			ft_slist_queue_push(t_slist *item, t_slist_queue *head);
t_slist			*ft_list_queue_pop(t_slist_queue *head);

#endif
