/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look_see.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 00:48:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 01:43:28 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		look_west(int first, t_fov *fov)
{
	if (fov->seen == first)
	{
		fov->y += fov->len;
		fov->x -= 1;
		fov->level += 1;
		fov->len += 2;
		return ;
	}
	fov->y--;
}

static void		look_south(int first, t_fov *fov)
{
	if (fov->seen == first)
	{
		fov->x += fov->len;
		fov->y += 1;
		fov->level += 1;
		fov->len += 2;
		return ;
	}
	fov->x--;
}

static void		look_east(int first, t_fov *fov)
{
	if (fov->seen == first)
	{
		fov->y -= fov->len;
		fov->x += 1;
		fov->level += 1;
		fov->len += 2;
		return ;
	}
	fov->y++;
}

static void		look_north(int first, t_fov *fov)
{
	if (fov->seen == first)
	{
		fov->x -= fov->len;
		fov->y -= 1;
		fov->level += 1;
		fov->len += 2;
		return ;
	}
	fov->x++;
}

t_square		*see(t_data *data, t_fov *fov)
{
	int			first;
	t_square	*square;

	square = get_square(data, fov->x, fov->y);
	first = SQUARE(fov->level) - 1;
	if (fov->seen == fov->last)
		return (NULL);
	else if (fov->o == N)
		look_north(first, fov);
	else if (fov->o == E)
		look_east(first, fov);
	else if (fov->o == S)
		look_south(first, fov);
	else if (fov->o == W)
		look_west(first, fov);
	return (square);
}
