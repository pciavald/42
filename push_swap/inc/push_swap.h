/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:29:04 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:48:11 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include "struct.h"

void	display(char *str, int args);
t_num	*last(t_num *list);
t_num	*make_list(char **list, int argc);

void	sa(t_num **l_a, t_num **l_b, int args);
void	sb(t_num **l_a, t_num **l_b, int args);
void	ss(t_num **l_a, t_num **l_b, int args);

void	pa(t_num **l_a, t_num **l_b, int args);
void	pb(t_num **l_a, t_num **l_b, int args);

void	ra(t_num **l_a, t_num **l_b, int args);
void	rb(t_num **l_a, t_num **l_b, int args);
void	rr(t_num **l_a, t_num **l_b, int args);

void	rra(t_num **l_a, t_num **l_b, int args);
void	rrb(t_num **l_a, t_num **l_b, int args);
void	rrr(t_num **l_a, t_num **l_b, int args);
#endif
