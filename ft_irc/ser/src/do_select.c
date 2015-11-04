/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:11:10 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/24 20:41:59 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bircd.h"

void	do_select(t_env *e)
{
	struct timeval		tv;

	tv.tv_sec = 5;
	e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, &tv);
}
