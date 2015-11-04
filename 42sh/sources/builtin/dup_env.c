/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:08:42 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/13 16:16:08 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** dup_env() returns a copy of the environnement array
*/
#include <libft.h>
#include <stdlib.h>
#include <string.h>

char	**dup_env(char **env)
{
	char	**dup;
	int		i;

	i = 0;
	while (env[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		dup[i] = ft_strdup(env[i]);
	dup[i] = NULL;
	return (dup);
}
