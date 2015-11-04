/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_delfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:51:12 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 00:42:53 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** remove the first action of a given action list
*/

#include "server.h"
#include <stdlib.h>

void	action_delfirst(t_alist **alist)
{
	t_alist	*tmp;

	if (*alist)
	{
		tmp = *alist;
		*alist = (*alist)->next;
		if (tmp->cmd)
			free_split(tmp->cmd);
		if (tmp->timer)
			free(tmp->timer);
		free(tmp);
	}
}
