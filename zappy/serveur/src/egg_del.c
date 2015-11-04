/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 13:07:02 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:29:57 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	egg_del(t_egg **list, t_egg *egg)
{
	t_egg	*current;

	if (egg->team)
		free(egg->team);
	if (egg == *list)
		*list = egg->next;
	else
	{
		current = *list;
		while (current->next != egg)
			current = current->next;
		if (current->next)
			current->next = current->next->next;
		free(egg);
	}
}
