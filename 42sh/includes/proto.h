/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:08:17 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 23:00:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <struct.h>
# include <macro.h>

/*
** ./sources/init.c
*/
void	init(char **envp);
/*
** ./sources/main.c
*/
t_data	*data(void);
/*
** ./sources/termcaps.c
*/
void	tinit(t_data *data);
void	treset(t_data *data);
int		tputchar(int c);
void	tputstr(char *str);
/*
** ./source/parser/parser.c
*/
void	prompt(void);

#endif
