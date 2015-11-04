/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_spells.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:32:56 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:34:33 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	clean_spells(t_data *data)
{
	while (data->spells)
		spell_del(&data->spells, data->spells);
}
