/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 02:43:34 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 16:27:44 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>
#include <fcntl.h>
#include <helpers.h>
#include <string.h>
#include <struct.h>

int			exec_inf(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		new_fd[4];

	(void)fd;
	(void)fd2;
	new_fd[0] = 0;
	new_fd[1] = 0;
	new_fd[3] = 0;
	if ((new_fd[2] = open(lex->left->lex, O_RDONLY)) == -1)
	{
		put_error(lex->left->lex, NULL);
		return (-1);
	}
	return (exec_lex(lex->right, envp, new_fd, NULL));
}
