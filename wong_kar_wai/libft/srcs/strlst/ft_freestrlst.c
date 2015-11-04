/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:42:40 by tcharlat          #+#    #+#             */
/*   Updated: 2014/05/22 18:42:43 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlst.h"
#include <stdlib.h>

void			ft_freestrlst(t_strlst *start, int clear)
{
	t_strlst	*mem;

	while (start)
	{
		if (clear)
			free(start->str);
		mem = start;
		start = start->next;
		free(mem);
	}
}
