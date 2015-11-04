/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_tna.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:49:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:50:49 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_tna(t_data *data, int cs)
{
	t_tlist		*team;

	team = data->teams;
	while (team)
	{
		dprintf(cs, "tna %s\n", team->name);
		team = team->next;
	}
}
