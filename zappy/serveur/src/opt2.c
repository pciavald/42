/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:15:03 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 11:15:35 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	get_width(char *arg, t_data *data)
{
	if (arg)
		data->x = atoi(arg);
	else
		usage(data->name);
}

void	get_height(char *arg, t_data *data)
{
	if (arg)
		data->y = atoi(arg);
	else
		usage(data->name);
}
