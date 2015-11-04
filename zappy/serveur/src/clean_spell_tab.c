/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_spell_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:35:14 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 20:37:51 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	clean_spell_tab(t_data *data)
{
	int		i;

	i = -1;
	while (++i < 7)
		free(data->spell_tab[i]);
	free(data->spell_tab);
}
