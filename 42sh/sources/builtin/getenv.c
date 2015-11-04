/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:09:40 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/17 02:18:17 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_getenv(char **envp, char *key)
{
	char	*name;
	int		name_len;
	int		i;

	name = ft_strjoin(key, "=");
	name_len = (int)ft_strlen(name);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], name, name_len))
		i++;
	free(name);
	if (envp[i])
		return (ft_strdup(envp[i] + name_len));
	else
		return (NULL);
}
