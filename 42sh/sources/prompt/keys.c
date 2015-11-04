/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 01:56:48 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 16:10:58 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proto.h>

int			is_end(char *key)
{
	t_line	*l;

	if ((key[0] == 27 && key[1] == 'O' && key[2] == 'F' && key[3] == 0)
			|| (key[0] == 27 && key[1] == '[' && key[2] == 'F' && key[3] == 0)
			|| (key[0] == 5 && key[1] == 0 && key[2] == 0 && key[3] == 0))
	{
		if ((data()->cur == NONE)
				|| (data()->cur == CURRENT && !data()->current)
				|| (data()->cur == CURRENT && !data()->current->edit))
			return (1);
		else if (data()->cur != CURRENT && data()->cur != NONE)
		{
			l = data()->history;
			while (l->id != data()->cur)
				l = l->next;
			if (l->edit)
				l->edit = -1;
		}
		else
			data()->current->edit = -1;
		return (1);
	}
	return (0);
}
