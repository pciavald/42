/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
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

#ifndef FT_DLIST_H
# define FT_DLIST_H
# include <stddef.h>
# define FT_DL_DATA(type, dlist) (type *)(dlist + 1)
# define FT_DL_HEAD(data) ((t_dlist *)data) - 1
# define FT_NEW_DL(type) ft_new_dlist(sizeof(type))
# define FT_NEW_DL_DATA(type) FT_DL_DATA(type, ft_newdlist(sizeof(type)))

typedef struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlist_malloc(size_t size);
void				ft_dlist_add(t_dlist *new, t_dlist *prev, t_dlist *next);
void				ft_dlist_remove(t_dlist *item);
#endif
