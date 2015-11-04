/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:02:08 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 12:06:15 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_gcmd	new_command(char *cmd, void (*fct)(t_data*, int, char**))
{
	t_gcmd	c;

	c.cmd = strdup(cmd);
	c.fct = fct;
	return (c);
}

void			create_gcmds(t_data *data)
{
	data->gcmds[0] = new_command("bct", &gcmd_bct);
	data->gcmds[1] = new_command("mct", &gcmd_mct);
	data->gcmds[2] = new_command("msz", &gcmd_msz);
	data->gcmds[3] = new_command("pin", &gcmd_pin);
	data->gcmds[4] = new_command("plv", &gcmd_plv);
	data->gcmds[5] = new_command("ppo", &gcmd_ppo);
	data->gcmds[6] = new_command("sgt", &gcmd_sgt);
	data->gcmds[7] = new_command("sst", &gcmd_sst);
	data->gcmds[8] = new_command("tna", &gcmd_tna);
}
