/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 00:20:20 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 18:58:29 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <executer.h>
#include <libft.h>
#include <proto.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int		get_option(char *arg, char *option)
{
	int		i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i] == 'i')
			*option = 'i';
		else
		{
			ft_printf_fd(2, "env: illegal option -- %c", arg[i]);
			ft_putstr_fd("usage: env [-i] [name=value ...] ", 2);
			ft_putendl_fd("[utility [argument ...]]\n", 2);
			return (-1);
		}
	}
	return (0);
}

static int		exec_env(char **argv, int i, char **envp)
{
	pid_t	pid;
	int		status;

	if (argv[i])
	{
		if (ft_strstr(BUILTIN, argv[i]))
			return (builtin(argv + i, &envp));
		else
		{
			pid = fork();
			if (!pid)
				exec(argv + i, &envp);
			else
			{
				waitpid(pid, &status, 0);
				return (status);
			}
		}
	}
	else
		put_env(envp);
	return (0);
}

int				sh_env(char **argv, char ***envp)
{
	int		i;
	char	option;
	char	**env_tmp;
	char	**tmp;

	option = 0;
	i = 0;
	while (argv[++i] && argv[i][0] == '-')
	{
		if ((get_option(argv[i], &option)) == -1)
			return (-1);
	}
	if (option == 'i')
		env_tmp = new_env();
	else
		env_tmp = dup_env(*envp);
	while (argv[i] && ft_strchr(argv[i], '='))
	{
		tmp = ft_strsplit(argv[i], '=');
		set_envline(tmp[0], tmp[1], &env_tmp);
		free(tmp);
		i++;
	}
	return (exec_env(argv, i, env_tmp));
}
