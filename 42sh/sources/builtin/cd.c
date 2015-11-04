/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:02:25 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 23:29:28 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <helpers.h>
#include <libft.h>
#include <proto.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>

static char	get_option(char *arg)
{
	char	option;
	int		i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i] == 'L' || arg[i] == 'P')
			option = arg[i];
		else
		{
			ft_printf_fd(2, "cd: invalid option: -%c.\n", arg[i]);
			return (-1);
		}
	}
	return (option);
}

static int	pwd_update(char ***envp)
{
	char	*oldpwd;
	char	*pwd;

	if (!(oldpwd = ft_getenv(*envp, "PWD")))
		oldpwd = ft_strdup("");
	if (!(pwd = getcwd(NULL, MAXPATHLEN)))
		pwd = ft_strdup("");
	set_envline("OLDPWD", oldpwd, envp);
	set_envline("PWD", pwd, envp);
	free(pwd);
	free(oldpwd);
	return (0);
}

int			sh_cd(char **argv, char ***envp)
{
	char	*dest_path;
	char	option;
	int		i;

	option = 'L';
	i = 0;
	while (argv[++i] && argv[i][0] == '-' && argv[i][1])
	{
		if ((option = get_option(argv[i])) == -1)
			return (-1);
	}
	if (!(dest_path = get_path(argv + i, envp, option)) || !dest_path[0])
		return (-1);
	if (!chdir(dest_path))
	{
		free(dest_path);
		return (pwd_update(envp));
	}
	else
	{
		put_error("cd", argv[i]);
		free(dest_path);
		return (-1);
	}
}
