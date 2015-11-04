/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcmd_pin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:22:17 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 11:35:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

/*
** "pin #n X Y q q q q q q q\n" "pin #n\n" Inventaire d’un joueur.
*/

void	gcmd_pin(t_data *data, int cs, char **cmd)
{
	t_player	*player;

	if (!cmd[1] || cmd[1][0] != '#'
		|| !(player = get_player(data, atoi(cmd[1] + 1))))
		gui_sbp(NULL, cs);
	else
		gui_pin(player, cs);
}
