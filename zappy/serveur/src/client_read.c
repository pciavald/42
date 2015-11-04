/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 13:34:32 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 18:09:22 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static void	bufread_handl2(t_data *data, char *str, int cs)
{
	cmd_handl(data, str, cs);
	free(str);
}

static void	bufread_handl(t_data *data, char *str, int cs)
{
	int		i;
	int		len;

	i = 0;
	while (str[i])
	{
		len = 0;
		while (str[i + len] && str[i + len] != '\n')
			len++;
		if (str[i + len])
		{
			if (len)
				bufread_handl2(data, strsub(str, i, len), cs);
			i += len + 1;
			len = 0;
		}
		if (!str[i + len])
		{
			strncpy(str, str + i, BUF_SIZE);
			return ;
		}
	}
}

void		client_read(t_data *data, int cs)
{
	int		blen;

	blen = strlen(data->fds[cs].buf_read);
	if (recv(cs, data->fds[cs].buf_read + blen, BUF_SIZE - blen, 0) <= 0)
	{
		if (data->fds[cs].type == FD_PLAYER)
			player_death(data, get_player(data, cs));
		else
			close(cs);
	}
	else if (data->fds[cs].buf_read[strlen(data->fds[cs].buf_read) - 1]
			== '\n')
		bufread_handl(data, data->fds[cs].buf_read, cs);
}
