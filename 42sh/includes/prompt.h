/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 19:09:52 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:41:52 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <struct.h>

/*
** ./sources/prompt/enter.c
*/
void	clean_history_tmp(void);
/*
** ./sources/prompt/prompt.c
*/
void	prompt(void);
void	show_line(int enter);
t_char	*del_str(t_char *del);
t_line	*del_line(t_line *del);
/*
** ./sources/prompt/read.c
*/
void	read_line(void);
/*
** ./sources/prompt/tools.c
*/
t_char	*cur_char(t_char *c, int i);
int		listlen(t_char *c);
t_char	*dup_char(t_char *lechar);
t_char	*dup_str(t_char *orig);
t_line	*dup_line(t_line *orig);
/*
** ./sources/prompt/nl_handler.c
*/
void	nl_handler(void);

#endif
