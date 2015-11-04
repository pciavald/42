/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 01:44:26 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 22:38:15 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <executer.h>
#include <helpers.h>
#include <libft.h>
#include <proto.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	io_handle(int *fd, int *fd2)
{
	if (fd && fd[0])
		dup2(fd[0], 0);
	if (fd && fd[2])
	{
		dup2(fd[2], 0);
		close(fd[2]);
	}
	if (fd && fd[3])
	{
		dup2(fd[3], 1);
		close(fd[3]);
	}
	if (fd2 && fd2[0])
		dup2(fd2[0], 0);
	if (fd2 && fd2[2])
	{
		dup2(fd2[2], 0);
		close(fd2[2]);
	}
	if (fd2 && fd2[3])
	{
		dup2(fd2[3], 2);
		close(fd2[3]);
	}
}

static int	fork_handle(char **argv, char ***envp, int *fd, int *fd2)
{
	pid_t	pid;
	int		status;

	status = -1;
	pid = fork();
	if (!pid)
	{
		io_handle(fd, fd2);
		exec(argv, envp);
	}
	else
		waitpid(pid, &status, 0);
	return (status);
}

int			exec_simple(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	char	**argv;
	int		status;

	status = 0;
	argv = ft_strsplit(lex->lex, ' ');
	if (fd && fd[1])
		close(fd[1]);
	if (fd2 && fd2[1])
		close(fd2[1]);
	if (!argv[0])
		return (-1);
	if (is_builtin(argv[0]))
	{
		io_handle(fd, fd2);
		status = builtin(argv, envp);
	}
	else
		status = fork_handle(argv, envp, fd, fd2);
	free_split(argv);
	dup2(data()->fd_std[0], 0);
	dup2(data()->fd_std[1], 1);
	dup2(data()->fd_std[2], 2);
	return (status);
}
