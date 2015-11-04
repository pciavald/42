/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 01:48:51 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:35:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <struct.h>

typedef int		(*t_exec_fn)(t_lex *, char ***, int *, int *);

/*
** executer.c
*/
void	exec(char **argv, char ***envp);
int		exec_lex(t_lex *lex, char ***envp, int *fd, int *fd2);
/*
** exec_inf.c
*/
int		exec_inf(t_lex *lex, char ***envp, int *fd, int *fd2);
/*
** exec_pipe.c
*/
int		exec_pipe(t_lex *lex, char ***envp, int *fd, int *fd2);
/*
** exec_separators.c
*/
int		exec_semicol(t_lex *lex, char ***envp, int *fd, int *fd2);
int		exec_or(t_lex *lex, char ***envp, int *fd, int *fd2);
int		exec_and(t_lex *lex, char ***envp, int *fd, int *fd2);
/*
** exec_simple.c
*/
int		exec_simple(t_lex *lex, char ***envp, int *fd, int *fd2);
/*
** exec_sup.c
*/
int		exec_sup(t_lex *lex, char ***envp, int *fd, int *fd2);
int		exec_sup2(t_lex *lex, char ***envp, int *fd, int *fd2);
int		exec_supsup(t_lex *lex, char ***envp, int *fd, int *fd2);
int		exec_supsup2(t_lex *lex, char ***envp, int *fd, int *fd2);

#endif
