/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 10:22:52 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:49:35 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

static void		gui_handl(t_data *data, char **cmd, int cs)
{
	int		i;

	i = -1;
	while (++i < GCMD_NB)
	{
		if (!strcmp(cmd[0], data->gcmds[i].cmd))
		{
			data->gcmds[i].fct(data, cs, cmd);
			break ;
		}
	}
	if (i == GCMD_NB)
		gui_suc(NULL, cs);
}

static void		player_handl(t_data *data, char **cmd, int cs)
{
	int		i;

	i = -1;
	while (++i < CMD_NB)
	{
		if (!strcmp(cmd[0], data->cmds[i].cmd))
		{
			action_add(data, &data->fds[cs].player.actions, data->cmds[i],
					cmd);
			break ;
		}
	}
	if (i == CMD_NB)
		dprintf(cs, "command unknown\n");
}

static void		client_handl(t_data *data, char *cmd, int cs)
{
	if (!strcmp(cmd, "GRAPHIC"))
	{
		printf("New GUI connected\n");
		data->fds[cs].type = FD_GUI;
		gui_init(data, cs);
	}
	else
	{
		printf("New player connected\n");
		team_join(data, cmd, cs);
	}
}

void			cmd_handl(t_data *data, char *cmd, int cs)
{
	char	**cmd_split;

	if (cmd)
	{
		printf("received cmd from client #%d : %s\n", cs, cmd);
		cmd_split = strsplit(cmd, ' ');
		if (data->fds[cs].type == FD_CLIENT)
			client_handl(data, cmd, cs);
		else if (data->fds[cs].type == FD_PLAYER)
			player_handl(data, cmd_split, cs);
		else if (data->fds[cs].type == FD_GUI)
			gui_handl(data, cmd_split, cs);
		free_split(cmd_split);
	}
}
