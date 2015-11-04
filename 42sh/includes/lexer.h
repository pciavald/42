/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:59:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:38:33 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <struct.h>

/*
** ./sources/lexer/blanks.c
*/
void	blanks(t_lex *lex);
/*
** ./sources/lexer/lexer.c
*/
void	lexer(t_char *line);
/*
** ./sources/lexer/logic.c
*/
void	logic_and(t_lex *lex);
void	logic_or(t_lex *lex);
/*
** ./sources/lexer/other.c
*/
int		other(t_lex *lex);
void	dr_redir_amp(t_lex *lex);
void	r_redir_amp(t_lex *lex);
/*
** ./sources/lexer/redir.c
*/
void	r_redir(t_lex *lex);
void	dr_redir(t_lex *lex);
void	l_redir(t_lex *lex);
void	pipe_redir(t_lex *lex);
/*
** ./sources/lexer/separators.c
*/
void	semicolon(t_lex *lex);
/*
** ./sources/lexer/tools.c
*/
t_lex	*make_lex(char *str, char *op, int len);
char	*make_line(t_char *c);

#endif
