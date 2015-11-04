/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 11:32:03 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 11:45:56 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

t_player	*get_player(t_data *data, int cs)
{
	if (cs < 0 || cs >= data->max_fd || data->fds[cs].type != FD_PLAYER)
		return (NULL);
	else
		return (&data->fds[cs].player);
}
