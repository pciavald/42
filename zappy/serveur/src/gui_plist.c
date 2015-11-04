/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_plist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:39:46 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 15:45:28 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	gui_plist(t_data *data, int cs)
{
	t_tlist		*team;
	t_plist		*plist;

	team = data->teams;
	while (team)
	{
		plist = team->list;
		while (plist)
		{
			gui_pnw(plist->player, cs);
			plist = plist->next;
		}
		team = team->next;
	}
}
