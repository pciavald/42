/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_smg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:45:34 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:46:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "smg M\n" - Message du serveur.
*/

#include "server.h"
#include <stdio.h>

void	gui_smg(char *msg, int cs)
{
	dprintf(cs, "smg %s\n", msg);
}
