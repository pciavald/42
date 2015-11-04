/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:17:51 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:17:54 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlst.h"
#include "ft_mem.h"
#include "ft_str.h"

char			**ft_lsttoarray(t_strlst *lst, int dup)
{
	char		**ret;
	t_strlst	*index;
	int			size;

	size = 0;
	index = lst;
	while (index)
	{
		index = index->next;
		size++;
	}
	ret = ft_memalloc((size + 1) * sizeof(char *));
	size = 0;
	while (lst)
	{
		if (dup)
			ret[size] = ft_strdup(lst->str);
		else
			ret[size] = lst->str;
		lst = lst->next;
		size++;
	}
	return (ret);
}
