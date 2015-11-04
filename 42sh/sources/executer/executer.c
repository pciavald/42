/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:24:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:20:38 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <executer.h>
#include <fcntl.h>
#include <libft.h>
#include <proto.h>
#include <stdlib.h>
#include <struct.h>
#include <sys/wait.h>
#include <unistd.h>

static char	**get_pathlist(char **envp)
{
	char	*path_line;
	char	**path_list;

	if ((path_line = ft_getenv(envp, "PATH")))
	{
		path_list = ft_strsplit(path_line, ':');
		free(path_line);
	}
	else
	{
		path_list = (char **)malloc(sizeof(char *) * 2);
		path_list[0] = "/bin";
		path_list[1] = NULL;
	}
	return (path_list);
}

void		exec(char **argv, char ***envp)
{
	char	**path_list;
	char	*path;
	int		i;

	execve(*argv, argv, *envp);
	path_list = get_pathlist(*envp);
	i = -1;
	while (path_list && path_list[++i])
	{
		path = (char *)malloc(sizeof(char)
				* (ft_strlen(path_list[i]) + ft_strlen(*argv) + 2));
		ft_strcpy(path, path_list[i]);
		ft_strcat(path, "/");
		ft_strcat(path, *argv);
		execve(path, argv, *envp);
		free(path);
	}
	ft_printf_fd(2, "42sh: %s: command not found.\n", *argv);
	exit(-1);
}

int			exec_lex(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int			ret;
	t_exec_fn	exec[12];

	exec[0] = exec_simple;
	exec[1] = exec_semicol;
	exec[2] = exec_or;
	exec[3] = exec_and;
	exec[4] = exec_inf;
	exec[5] = NULL;
	exec[6] = exec_pipe;
	exec[7] = NULL;
	exec[8] = exec_sup;
	exec[9] = exec_sup2;
	exec[10] = exec_supsup;
	exec[11] = exec_supsup2;
	ret = exec[lex->flag](lex, envp, fd, fd2);
	return (ret);
}
