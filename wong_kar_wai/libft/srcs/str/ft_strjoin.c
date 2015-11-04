/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:43 by tcharlat          #+#    #+#             */
/*   Updated: 2013/11/22 16:33:44 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	presize;
	size_t	sufsize;
	char	*tmp;

	presize = ft_strlen(s1);
	sufsize = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (presize + sufsize + 1));
	if (!tmp)
		return (NULL);
	tmp[presize + sufsize] = 0;
	while (sufsize--)
		tmp[presize + sufsize] = s2[sufsize];
	while (presize--)
		tmp[presize] = s1[presize];
	return (tmp);
}
