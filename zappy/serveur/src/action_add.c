/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 20:27:34 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 00:06:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <sys/time.h>

void	action_add(t_data *data, t_alist **actions, t_cmd action, char **cmd)
{
	t_alist		*new;
	t_alist		*tmp;
	t_timeval	now;

	(void)data;
	new = (t_alist*)malloc(sizeof(t_alist));
	new->action = action.fct;
	new->cmd = split_dup(cmd);
	gettimeofday(&now, NULL);
	new->timer = NULL;
	new->next = NULL;
	if (*actions == NULL)
		*actions = new;
	else
	{
		tmp = *actions;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
