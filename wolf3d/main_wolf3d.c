/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:21:57 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_wolf3d.h"

int				main(int argc, char **argv)
{
	t_env		e;

	(void)argv;
	if (argc != 1)
		error("Error : No argument needed");
	init_e(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "wolf3d");
	e.imlx = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop_hook(e.mlx, draw_img, &e);
	mlx_loop(e.mlx);
	mlx_destroy_image(e.mlx, e.imlx);
	return (0);
}

void			error(char *s)
{
	if (s)
		write(2, &(*s), ft_strlen(s));
	write(2, "\n", 1);
	exit(0);
}
