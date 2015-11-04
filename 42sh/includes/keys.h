/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 19:50:48 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:34 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

int		is_arrow_up(char *key);
int		is_arrow_down(char *key);
int		is_arrow_right(char *key);
int		is_arrow_left(char *key);

int		is_delete(char *key);
int		is_backspace(char *key);

int		is_end(char *key);

int		is_ctrl_a(char *key);
int		is_ctrl_d(char *key);
int		is_ctrl_l(char *key);
int		is_other(char *key);

int		is_ascii(char *key);
int		is_enter(char *key);

#endif
