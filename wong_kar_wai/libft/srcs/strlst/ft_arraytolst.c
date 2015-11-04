/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytolst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:18:05 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:18:06 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlst.h"
#include "ft_mem.h"
#include "ft_str.h"

t_strlst		*ft_arraytolst(char **array, int dup)
{
	size_t		index;
	t_strlst	*start;
	t_strlst	*mem;
	t_strlst	*tmp;

	index = 0;
	start = NULL;
	while (array[index])
	{
		tmp = ft_memalloc(sizeof(t_strlst));
		if (dup)
			tmp->str = ft_strdup(array[index]);
		else
			tmp->str = array[index];
		if (!start)
			start = tmp;
		else
			mem->next = tmp;
		mem = tmp;
		index++;
	}
	return (start);
}
