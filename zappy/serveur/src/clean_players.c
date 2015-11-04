/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:22:41 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:25:37 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	clean_players(t_plist **plist)
{
	t_plist		*current;
	t_plist		*tmp;

	current = *plist;
	while (current)
	{
		tmp = current;
		current = current->next;
		player_del(plist, tmp->player);
	}
}
