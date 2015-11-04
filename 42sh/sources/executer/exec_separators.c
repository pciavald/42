/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_separators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 02:38:46 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 16:28:30 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>
#include <string.h>
#include <struct.h>

int			exec_semicol(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		ret;

	(void)fd;
	(void)fd2;
	exec_lex(lex->left, envp, NULL, NULL);
	ret = exec_lex(lex->right, envp, NULL, NULL);
	return (ret);
}

int			exec_or(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		ret;

	(void)fd;
	(void)fd2;
	if ((ret = exec_lex(lex->left, envp, NULL, NULL)))
		exec_lex(lex->right, envp, NULL, NULL);
	return (ret);
}

int			exec_and(t_lex *lex, char ***envp, int *fd, int *fd2)
{
	int		ret;

	(void)fd;
	(void)fd2;
	if (!(ret = exec_lex(lex->left, envp, NULL, NULL)))
		exec_lex(lex->right, envp, NULL, NULL);
	return (ret);
}
