/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:02:44 by tcharlat          #+#    #+#             */
/*   Updated: 2015/03/01 23:02:45 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	pow2(int ln2)
{
	int		ret;

	ret = 1;
	while (ln2--)
		ret *= 2;
	return (ret);
}

void		victory(t_data *data)
{
	int		index;

	index = 0;
	while (index < BSIZE)
	{
		if (pow2(data->game[index]) >= WIN_VALUE)
			data->victory = 1;
		index++;
	}
}
