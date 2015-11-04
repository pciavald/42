/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 02:53:09 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 22:42:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <executer.h>
#include <helpers.h>
#include <libft.h>
#include <proto.h>
#include <stdlib.h>
#include <unistd.h>

static int	*pipe_handle(int *fd, int *fd2, int *new_fd)
{
	pipe(new_fd);
	new_fd[2] = 0;
	new_fd[3] = 0;
	if (fd && fd[1])
		close(fd[1]);
	if (fd2 && fd2[1])
		close(fd2[1]);
	return (new_fd);
}

static void	io_handle(int *fd, int *fd2)
{
	if (fd && fd[0])
		dup2(fd[0], 0);
	if (fd && fd[2])
	{
		dup2(fd[2], 0);
		close(fd[2]);
	}
	if (fd2 && fd2[0])
		dup2(fd2[0], 0);
	if (fd2 && fd2[2])
	{
		dup2(fd2[2], 0);
		close(fd2[2]);
	}
}

static void	fork_handle(int **fd_tab, char **argv, char ***envp, t_lex *lex)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		io_handle(fd_tab[1], fd_tab[2]);
		close(fd_tab[0][0]);
		dup2(fd_tab[0][1], 1);
		if (is_builtin(argv[0]))
			exit(builtin(argv, envp));
		else
			exec(argv, envp);
	}
	else
		exec_lex(lex->right, envp, fd_tab[0], NULL);
}

int			exec_pipe(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	char	**argv;
	int		status;
	int		new_fd[4];
	int		**tab;

	status = 0;
	argv = ft_strsplit(lex->left->lex, ' ');
	pipe_handle(fd, fd2, new_fd);
	tab = (int **)malloc(sizeof(int *) * 3);
	tab[0] = new_fd;
	tab[1] = fd;
	tab[2] = fd2;
	fork_handle(tab, argv, envp, lex);
	free(tab);
	free_split(argv);
	return (status);
}
