/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:02:52 by gexbraya          #+#    #+#             */
/*   Updated: 2014/03/27 19:49:36 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proto.h>
#include <stdlib.h>

t_char			*del_str(t_char	*del)
{
	t_char		*prev;

	while (del)
	{
		prev = del;
		del = del->next;
		free(prev);
	}
	return (NULL);
}

t_line			*del_line(t_line *del)
{
	if (del)
	{
		del->tmp = del_str(del->tmp);
		del->line = del_str(del->line);
		free(del);
	}
	return (NULL);
}
