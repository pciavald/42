/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:53:05 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 23:27:13 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <struct.h>

/*
** ./sources/helpers/error.c
*/
void	put_error(char *name, char *str);
char	*ft_strerror(void);
/*
** ./sources/helpers/free.c
*/
void	free_lex(t_lex *lex);
void	free_pathlist(t_path *list);
/*
** ./sources/helpers/quit.c
*/
void	quit(char *str, int status);
/*
** ./sources/helpers/signals.c
*/
void	sighandler(int signum);
/*
** ./sources/helpers/split.c
*/
void	free_split(char **array);
int		count_split(char **array);

#endif
