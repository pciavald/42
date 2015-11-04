/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:58:08 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:47:35 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

static t_tlist	*find_team(t_data *data, int cs)
{
	t_tlist		*team;
	t_plist		*list;
	t_player	*player;

	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			player = list->player;
			if (player->cs == cs)
				return (team);
			list = list->next;
		}
		team = team->next;
	}
	return (NULL);
}

static void		timer_init(t_data *data, t_timeval **timer)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
}

void			ccmd_max(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_tlist		*team;

	(void)cmd;
	if (*t == NULL)
		timer_init(data, t);
	else
	{
		if ((team = find_team(data, cs)) != NULL)
			dprintf(cs, "%i\n", team->slots);
	}
}
