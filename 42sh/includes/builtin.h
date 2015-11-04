/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:00:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:19:29 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define NB_BUILTIN		6
# define BUILTIN		"cd echo setenv unsetenv env exit"

typedef struct	s_builtin
{
	char		*name;
	int			(*fn)(char**, char***);
}				t_builtin;

int				builtin(char **argv, char ***envp);
int				is_builtin(char *name);
/*
** cd
*/
int				sh_cd(char **argv, char ***envp);
/*
** echo
*/
int				sh_echo(char **argv, char ***envp);
/*
** env
*/
int				sh_env(char **argv, char ***envp);
/*
** exit
*/
int				sh_exit(char **argv, char ***envp);
/*
** setenv
*/
int				sh_setenv(char **argv, char ***env);
/*
** unsetenv
*/
int				sh_unsetenv(char **argv, char ***env);
/*
** common tools
*/
char			**new_env(void);
char			**dup_env(char **env);
char			*ft_getenv(char **envp, char *key);
void			put_env(char **env);
void			set_envline(char *line_name, char *content, char ***env);
char			*get_path(char **argv, char ***envp, char option);
char			*path_simplifier(char *path);

#endif
