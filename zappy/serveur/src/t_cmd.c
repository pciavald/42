/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:51:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/22 23:12:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_cmd	new_command(char *cmd,
							void (*fct)(t_data*, int, char**, t_timeval**))
{
	t_cmd	c;

	c.cmd = strdup(cmd);
	c.fct = fct;
	return (c);
}

void			create_cmds(t_data *data)
{
	data->cmds[0] = new_command("avance", &ccmd_forward);
	data->cmds[1] = new_command("droite", &ccmd_right);
	data->cmds[2] = new_command("gauche", &ccmd_left);
	data->cmds[3] = new_command("voir", &ccmd_look);
	data->cmds[4] = new_command("inventaire", &ccmd_invent);
	data->cmds[5] = new_command("prend", &ccmd_take);
	data->cmds[6] = new_command("pose", &ccmd_drop);
	data->cmds[7] = new_command("expulse", &ccmd_push);
	data->cmds[8] = new_command("broadcast", &ccmd_bcast);
	data->cmds[9] = new_command("incantation", &ccmd_incant);
	data->cmds[10] = new_command("fork", &ccmd_fork);
	data->cmds[11] = new_command("connect_nbr", &ccmd_max);
}
