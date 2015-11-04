/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcmd_plv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:17:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 11:41:04 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "plv #n L\n" "plv #n\n" Niveau d’un joueur.
*/

#include "server.h"
#include <stdlib.h>

void	gcmd_plv(t_data *data, int cs, char **cmd)
{
	t_player	*player;

	if (!cmd[1] || cmd[1][0] != '#'
		|| !(player = get_player(data, atoi(cmd[1] + 1))))
		gui_sbp(NULL, cs);
	else
		gui_plv(player, cs);
}
