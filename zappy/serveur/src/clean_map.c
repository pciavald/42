/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:38:33 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:40:09 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	clean_map(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->x)
		free(data->map[i]);
	free(data->map);
}
