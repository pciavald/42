/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:24:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:16:00 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>
#include <fcntl.h>
#include <helpers.h>
#include <struct.h>
#include <string.h>

static void	fd_init(int *new_fd, int *fd)
{
	if (fd)
	{
		new_fd[0] = fd[0];
		new_fd[1] = fd[1];
		new_fd[2] = fd[2];
	}
	else
	{
		new_fd[0] = 0;
		new_fd[1] = 0;
		new_fd[2] = 0;
	}
}

int			exec_sup(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		new_fd[4];

	fd_init(new_fd, fd);
	if ((new_fd[3] = open(lex->left->lex,
					O_CREAT | O_TRUNC | O_WRONLY, 00755)) == -1)
	{
		put_error("lex->left->lex", NULL);
		return (-1);
	}
	return (exec_lex(lex->right, envp, new_fd, fd2));
}

int			exec_sup2(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		new_fd[4];
	int		new_fd2[4];

	fd_init(new_fd, fd);
	fd_init(new_fd2, fd2);
	if ((new_fd[3] = open(lex->left->lex,
					O_CREAT | O_TRUNC | O_WRONLY, 00755)) == -1
			|| (new_fd2[3] = open(lex->left->lex,
					O_CREAT | O_TRUNC | O_WRONLY, 00755)) == -1)
	{
		put_error("lex->left->lex", NULL);
		return (-1);
	}
	return (exec_lex(lex->right, envp, new_fd, new_fd2));
}

int			exec_supsup(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		new_fd[4];

	fd_init(new_fd, fd);
	if ((new_fd[3] = open(lex->left->lex,
					O_CREAT | O_APPEND | O_WRONLY, 00755)) == -1)
	{
		put_error("lex->left->lex", NULL);
		return (-1);
	}
	return (exec_lex(lex->right, envp, new_fd, fd2));
}

int			exec_supsup2(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		new_fd[4];
	int		new_fd2[4];

	fd_init(new_fd, fd);
	fd_init(new_fd2, fd2);
	if ((new_fd[3] = open(lex->left->lex,
					O_CREAT | O_APPEND | O_WRONLY, 00755)) == -1
			|| (new_fd2[3] = open(lex->left->lex,
					O_CREAT | O_APPEND | O_WRONLY, 00755)) == -1)
	{
		put_error("lex->left->lex", NULL);
		return (-1);
	}
	return (exec_lex(lex->right, envp, new_fd, new_fd2));
}
