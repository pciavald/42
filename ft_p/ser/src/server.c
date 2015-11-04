/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 13:47:53 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:39:34 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		execute_fn(char *str, int sock)
{
	char	**nm_tab;
	int		(*fn_tab[FN_N])(char **, int);
	int		i;
	char	**split;

	nm_tab = init_nm_tab();
	fn_tab[GET_N] = &get;
	fn_tab[PUT_N] = &put;
	fn_tab[CD_N] = &cd;
	fn_tab[QUIT_N] = &quit;
	fn_tab[HELP_N] = &help;
	split = ft_strsplit(str, ' ');
	i = 0;
	while (i < FN_N)
	{
		if (ft_strequ(split[0], nm_tab[i]))
		{
			fn_tab[i](split, sock);
			ft_freesplit(&split);
		}
		i++;
	}
	return (0);
}

void	notify(int pid, int *status, int cs)
{
	wait4(pid, status, WUNTRACED, NULL);
	if (WIFEXITED(status) == -1)
		client_status(ERROR, cs);
	else
		client_status(SUCCESS, cs);
}

int		execute(char *str, char *pwd, int cs)
{
	pid_t	pid;
	char	cmd[6 + ft_strlen(str)];
	char	*args;
	int		status;

	(void)pwd;
	if ((args = executable(&str)))
	{
		ft_strcpy(cmd, "/bin/");
		ft_strcat(cmd, str);
		pid = fork();
		if (!pid)
		{
			dup2(cs, 1);
			execl(cmd, args, NULL);
			exit(-1);
		}
		else
			notify(pid, &status, cs);
	}
	else
		execute_fn(str, cs);
	return (1);
}

void	receive(int cs, int id)
{
	char		pwd[BUF_LEN];
	char		buf[BUF_LEN];
	size_t		len;

	client_connect(id);
	getcwd(pwd, BUF_LEN);
	while (42)
	{
		len = recv(cs, buf, BUF_LEN - 1, 0);
		buf[len] = '\0';
		if (len == 0)
		{
			shutdown(cs, 0);
			close(cs);
			break ;
		}
		else
		{
			ft_putstr("Client asked execution of: ");
			ft_putendl(buf);
			execute(buf, pwd, cs);
		}
	}
	client_quit(id);
}

void	run(int sock)
{
	int			cs;
	socklen_t	cslen;
	t_sin		csin;
	pid_t		pid;
	int			id;

	id = 0;
	while (42)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		id++;
		pid = fork();
		if (!pid)
			receive(cs, id);
	}
}
