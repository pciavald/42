/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:23:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 19:10:13 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

static void	new_envline(char ***env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[0][i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (env[0][++i])
		tmp[i] = env[0][i];
	tmp[i++] = NULL;
	tmp[i] = NULL;
	free(*env);
	*env = tmp;
}

void		set_envline(char *line_name, char *content, char ***env)
{
	char	*name;
	int		name_len;
	int		i;

	name = ft_strjoin(line_name, "=");
	name_len = ft_strlen(name);
	i = 0;
	while (env[0][i] && ft_strncmp(name, env[0][i], name_len))
		i++;
	if (env[0][i])
		free(env[0][i]);
	else
		new_envline(env);
	env[0][i] = (char *)malloc(sizeof(char)
			* (name_len + ft_strlen(content) + 1));
	ft_strcpy(env[0][i], name);
	ft_strcat(env[0][i], content);
	free(name);
}
