/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 07:17:36 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 11:29:27 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*split_join(char **split)
{
	char	*str;
	int		len;
	int		i;

	if (!split)
		return (strdup(""));
	len = 0;
	i = -1;
	while (split[++i])
		len += strlen(split[i]) + 1;
	str = (char*)malloc(sizeof(char) * len);
	i = 0;
	strcat(str, split[i]);
	while (split[++i])
	{
		strcat(str, " ");
		strcat(str, split[i]);
	}
	return (str);
}
