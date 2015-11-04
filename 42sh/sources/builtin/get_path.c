/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:02:25 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:03:12 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>

static char	*get_homepath(char *path, char **envp)
{
	char	*cur_path;
	char	*dest_path;

	if (!(cur_path = ft_getenv(envp, "HOME")))
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return (NULL);
	}
	dest_path = (char *)malloc(sizeof(char)
			* (ft_strlen(cur_path) + ft_strlen(path)));
	ft_strcpy(dest_path, cur_path);
	ft_strcat(dest_path, path + 1);
	free(cur_path);
	return (dest_path);
}

static char	*path_constructor(char *path, char option, char ***envp)
{
	char	*cur_path;
	char	*dest_path;

	if (path[0] == '~')
		dest_path = get_homepath(path, *envp);
	else
	{
		cur_path = getcwd(NULL, MAXPATHLEN);
		dest_path = (char *)malloc(sizeof(char)
				* (ft_strlen(cur_path) + ft_strlen(path) + 2));
		ft_strcpy(dest_path, cur_path);
		ft_strcat(dest_path, "/");
		ft_strcat(dest_path, path);
		free(cur_path);
	}
	if (option == 'P')
		return (dest_path);
	else
		return (path_simplifier(dest_path));
}

char		*get_path(char **argv, char ***envp, char option)
{
	char	*dest_path;

	(void)option;
	if (!*argv)
	{
		if (!(dest_path = ft_getenv(*envp, "HOME")) || !dest_path[0])
			ft_putendl_fd("cd: HOME not set.", 2);
	}
	else if (ft_strequ(*argv, "-"))
	{
		if (!(dest_path = ft_getenv(*envp, "OLDPWD")) || !dest_path[0])
			ft_putendl_fd("cd: OLDPWD not set.", 2);
		else
			ft_putendl(dest_path);
	}
	else if (*argv[0] == '/')
		dest_path = ft_strdup(*argv);
	else
		dest_path = path_constructor(*argv, option, envp);
	return (dest_path);
}
