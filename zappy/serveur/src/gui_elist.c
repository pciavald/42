/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_elist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:49:37 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 15:52:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	gui_elist(t_data *data, int cs)
{
	t_egg	*egg;

	egg = data->eggs;
	while (egg)
	{
		gui_enw(egg, cs);
		egg = egg->next;
	}
}
