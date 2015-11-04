/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:39:30 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 21:48:43 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	quit_game(t_data *data)
{
	clean_teams(data);
	clean_eggs(data);
	clean_spells(data);
	clean_spell_tab(data);
	clean_map(data);
	free(data->fds);
	exit(0);
}
