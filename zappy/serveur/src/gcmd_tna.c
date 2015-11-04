/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcmd_tna.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:30:31 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 12:09:46 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gcmd_tna(t_data *data, int cs, char **cmd)
{
	(void)cmd;
	gui_tna(data, cs);
}
