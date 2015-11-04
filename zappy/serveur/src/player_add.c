/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 16:10:46 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 11:14:26 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	player_add(t_plist **plist, t_player *player)
{
	t_plist	*new;

	new = (t_plist*)malloc(sizeof(t_plist));
	new->player = player;
	new->next = *plist;
	*plist = new;
}
