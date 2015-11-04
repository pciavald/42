/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:33:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:46:18 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	win_check(t_data *data)
{
	t_tlist		*team;
	t_plist		*list;
	int			count;

	team = data->teams;
	while (team)
	{
		count = 0;
		list = team->list;
		while (list)
		{
			if (list->player->level == 8)
				count++;
			list = list->next;
		}
		if (count >= 6)
		{
			gui_broadcast(data, gui_seg, team);
			quit_game(data);
		}
		team = team->next;
	}
}
