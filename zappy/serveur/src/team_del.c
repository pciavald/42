/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:07:23 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:22:25 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	team_del(t_tlist **list, t_tlist *team)
{
	t_tlist		*current;

	if (team->name)
		free(team->name);
	if (team->list)
		clean_players(&team->list);
	if (team == *list)
		*list = team->next;
	else
	{
		current = *list;
		while (current->next && team != current->next)
			current = current->next;
		current->next = current->next->next;
	}
	free(team);
}
