/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:00:55 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:12:30 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	gui_init(t_data *data, int cs)
{
	gui_msz(data, cs);
	gui_sgt(data, cs);
	gui_mct(data, cs);
	gui_tna(data, cs);
	gui_plist(data, cs);
	gui_elist(data, cs);
}
