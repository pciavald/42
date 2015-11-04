/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:34:50 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:10:43 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>

static void	unset_envline(char *name, int name_len, char ***env)
{
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (env[0][++i])
	{
		if (ft_strnequ(env[0][i], name, name_len))
			j++;
	}
	tmp = (char **)malloc(sizeof(char *) * (i - j + 1));
	i = -1;
	j = 0;
	while (env[0][++i])
	{
		if (ft_strnequ(env[0][i], name, name_len))
			free(env[0][i]);
		else
			tmp[j++] = env[0][i];
	}
	tmp[j] = NULL;
	free(*env);
	*env = tmp;
}

int			sh_unsetenv(char **argv, char ***env)
{
	int		i;
	char	*name;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (-1);
	}
	else
	{
		i = 0;
		while (argv[++i])
		{
			name = ft_strjoin(argv[i], "=");
			unset_envline(name, ft_strlen(name), env);
			free(name);
		}
	}
	return (0);
}
