/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 22:45:53 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/26 20:47:19 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

static void		send(int cs, char **strings, int len)
{
	int			i;

	dprintf(cs, "{");
	i = 0;
	while (i < len)
	{
		if (strings[i])
		{
			dprintf(cs, "%s, ", strings[i]);
			free(strings[i]);
		}
		i++;
	}
	dprintf(cs, "\b\b}\n");
}

static void		timer_init(t_data *data, t_timeval **timer)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
}

static void		set_strings(char **strings, int len)
{
	int			i;

	i = 0;
	while (i < len)
		strings[i++] = NULL;
}

void			ccmd_look(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_square	*square;
	char		*strings[SQUARE(data->fds[cs].player.level + 1)];
	t_fov		fov;

	(void)cmd;
	if (*t == NULL)
		timer_init(data, t);
	else
	{
		fov.player = &(data->fds[cs].player);
		fov.cs = cs;
		fov.x = fov.player->x;
		fov.y = fov.player->y;
		fov.o = fov.player->o;
		fov.seen = 0;
		fov.last = SQUARE(fov.player->level + 1) - 1;
		fov.level = 1;
		fov.len = 1;
		set_strings(strings, SQUARE(fov.player->level + 1));
		while ((square = see(data, &fov)) != NULL)
			strings[fov.seen++] = concatenate(data, cs, square);
		send(cs, strings, SQUARE(data->fds[cs].player.level + 1));
	}
}
