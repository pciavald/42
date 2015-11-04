/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:23:01 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/17 16:23:03 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRLST_H
# define FT_STRLST_H

typedef struct		s_strlst
{
	char			*str;
	struct s_strlst	*next;
}					t_strlst;
t_strlst			*ft_arraytolst(char **array, int dup);
char				**ft_lsttoarray(t_strlst *lst, int dup);
void				ft_freestrlst(t_strlst *start, int clear);
#endif
