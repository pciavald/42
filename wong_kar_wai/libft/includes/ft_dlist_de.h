/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_de.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:31:51 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/18 13:31:52 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_DE_H
# define FT_DLIST_DE_H
# define FT_DL_BUFFER(type) (sizeof(t_dlist) + sizeof(type))
# include "ft_dlist.h"

typedef struct	s_de_dlist
{
	int			type;
	size_t		size;
	t_dlist		ends;
}				t_de_dlist;

void			ft_dlist_de_init_head(t_de_dlist *head, int type);
void			ft_dlist_de_buffer_set(
	t_de_dlist *head, size_t size, size_t num, char *buf);
void			ft_dlist_de_push_front(t_dlist *item, t_de_dlist *head);
void			ft_dlist_de_push_back(t_dlist *item, t_de_dlist *head);
t_dlist			*ft_dlist_de_pop_front(t_de_dlist *head);
t_dlist			*ft_dlist_de_pop_back(t_de_dlist *head);

#endif
