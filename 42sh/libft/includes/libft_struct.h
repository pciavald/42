/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:52:45 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 20:56:21 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_avl
{
	void			*content;
	size_t			content_size;
	struct s_avl	*left;
	struct s_avl	*right;
}					t_avl;

#endif
