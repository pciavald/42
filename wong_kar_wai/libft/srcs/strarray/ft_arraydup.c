/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:42:22 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:42:35 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arraydup(char **array)
{
	char	**ret;
	int		size;

	size = 0;
	while (array[size])
		size++;
	ret = (char **)malloc((size + 1) * sizeof(char *));
	size = 0;
	while (array[size])
	{
		ret[size] = ft_strdup(array[size]);
		size++;
	}
	ret[size] = NULL;
	return (ret);
}
