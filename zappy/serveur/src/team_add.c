/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 08:22:25 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 11:55:27 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	team_add(t_data *data, char *name)
{
	t_tlist		*new;

	if ((new = (t_tlist*)malloc(sizeof(t_tlist))) == NULL)
		perror("malloc");
	new->name = strdup(name);
	new->list = NULL;
	new->next = data->teams;
	data->teams = new;
}
