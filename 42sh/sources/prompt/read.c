/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:40:35 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 20:35:08 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <helpers.h>
#include <keys.h>
#include <macro.h>
#include <prompt.h>
#include <unistd.h>
#include <proto.h>

static void		init_tab(t_keys_fn *t_tab)
{
	t_tab[0] = is_arrow_up;
	t_tab[1] = is_arrow_down;
	t_tab[2] = is_arrow_left;
	t_tab[3] = is_arrow_right;
	t_tab[4] = is_ascii;
	t_tab[5] = is_ctrl_a;
	t_tab[6] = is_ctrl_d;
	t_tab[7] = is_ctrl_l;
	t_tab[8] = is_end;
	t_tab[9] = is_enter;
	t_tab[10] = is_delete;
	t_tab[11] = is_backspace;
	t_tab[12] = is_other;
}

static int		key_pressed(char *key)
{
	int			index;
	int			exit;
	t_keys_fn	t_tab[KEYS];

	init_tab(t_tab);
	index = 0;
	while (index < KEYS)
	{
		if ((exit = t_tab[index](key)) == 1)
			break ;
		else if (exit == EXIT)
			return (EXIT);
		index++;
	}
	return (0);
}

void			read_line(void)
{
	char		key[4];

	while (42)
	{
		show_line(0);
		key[0] = 0;
		key[1] = 0;
		key[2] = 0;
		key[3] = 0;
		read(STDIN, key, 4);
		if (key_pressed(key) == EXIT)
			quit("exit\n", 0);
	}
}
