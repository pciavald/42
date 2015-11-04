/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 22:47:14 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:48:12 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCT_H
# define PS_STRUCT_H

typedef struct			s_num
{
	int					n;
	struct s_num		*next;
}						t_num;

#endif
