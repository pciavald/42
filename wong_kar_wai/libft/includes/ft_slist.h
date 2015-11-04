/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 21:45:35 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/17 21:45:36 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** From the head structure, next is front, prev is back.
*/

#ifndef FT_SLIST_H
# define FT_SLIST_H
# include <stddef.h>
# define FT_SL_DATA(type, slist) (type *)(slist + 1)
# define FT_SL_HEAD(data) ((t_slist *)data) - 1
# define FT_NEW_SL(type) ft_new_slist(sizeof(type))
# define FT_NEW_SL_DATA(type) FT_SL_DATA(type, ft_newslist(sizeof(type)))

typedef struct		s_slist
{
	struct s_slist	*next;
}					t_slist;

t_slist				*ft_slist_malloc(size_t size);
void				ft_slist_add(t_slist *new, t_slist *prev, t_slist *next);
void				ft_slist_remove(t_slist *prev, t_slist *next);

#endif
