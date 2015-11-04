/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 20:02:16 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:46:37 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <string.h>

void	team_join(t_data *data, char *cmd, int cs)
{
	t_tlist		*teams;

	teams = data->teams;
	while (teams && strcmp(teams->name, cmd))
		teams = teams->next;
	if (teams)
	{
		if (teams->slots)
		{
			data->fds[cs].type = FD_PLAYER;
			dprintf(cs, "%d\n", --(teams->slots));
			player_init(data, teams, cs);
			dprintf(cs, "%d %d\n", data->x, data->y);
			printf("client #%d joined team : %s\n", cs, teams->name);
		}
		else
			dprintf(cs, "no slot available\n");
	}
	else
		dprintf(cs, "no such team\n");
}
