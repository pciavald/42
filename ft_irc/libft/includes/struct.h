/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 19:58:01 by pciavald          #+#    #+#             */
/*   Updated: 2014/04/27 19:43:28 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdarg.h>
# include <string.h>

# define NB_OPT		13

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
