/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_egg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 05:49:51 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:48:20 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <sys/time.h>

static void		check_egg_food(t_data *data, t_egg *egg, t_timeval *now)
{
	t_tlist		*team;
	t_timeval	step;

	step = time_add(data, &egg->food_t, FOOD_T);
	if (time_diff(&step, now) >= 0)
	{
		egg->food--;
		egg->food_t = step;
	}
	if (!egg->food)
	{
		team = data->teams;
		while (team)
		{
			if (!strcmp(team->name, egg->team))
			{
				team->slots--;
				break ;
			}
			team = team->next;
		}
		gui_broadcast(data, gui_edi, egg);
		egg_del(&data->eggs, egg);
	}
}

static void		check_egg_birth(t_data *data, t_egg *egg, t_timeval *now)
{
	t_tlist	*team;

	if (time_diff(&egg->birth, now) >= 0)
	{
		egg->ready = 1;
		team = data->teams;
		while (team && strcmp(team->name, egg->team))
			team = team->next;
		team->slots++;
		gui_broadcast(data, gui_eht, egg);
	}
}

void			routine_egg(t_data *data)
{
	t_egg		*egg;
	t_egg		*tmp;
	t_timeval	now;

	gettimeofday(&now, NULL);
	egg = data->eggs;
	while (egg)
	{
		tmp = egg;
		egg = egg->next;
		if (tmp->ready)
			check_egg_food(data, tmp, &now);
		else
			check_egg_birth(data, tmp, &now);
	}
}
