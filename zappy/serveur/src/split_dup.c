/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 20:32:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 00:41:39 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	**split_dup(char **split)
{
	int		i;
	char	**dup;

	i = 0;
	while (split[i])
		i++;
	dup = (char**)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (split[++i])
		dup[i] = strdup(split[i]);
	dup[i] = NULL;
	return (dup);
}
