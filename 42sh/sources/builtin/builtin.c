/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:02:11 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:57:11 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>

static void		init_tab(t_builtin *tab)
{
	tab[0].name = "setenv";
	tab[0].fn = sh_setenv;
	tab[1].name = "unsetenv";
	tab[1].fn = sh_unsetenv;
	tab[2].name = "echo";
	tab[2].fn = sh_echo;
	tab[3].name = "cd";
	tab[3].fn = sh_cd;
	tab[4].name = "env";
	tab[4].fn = sh_env;
	tab[5].name = "exit";
	tab[5].fn = sh_exit;
}

int				builtin(char **argv, char ***envp)
{
	t_builtin	tab[NB_BUILTIN];
	int			index;

	init_tab(tab);
	index = 0;
	while (index < NB_BUILTIN)
	{
		if (ft_strequ(argv[0], tab[index].name))
			return (tab[index].fn(argv, envp));
		index++;
	}
	return (0);
}

int				is_builtin(char *name)
{
	t_builtin	tab[NB_BUILTIN];
	int			index;

	init_tab(tab);
	index = -1;
	while (++index < NB_BUILTIN)
	{
		if (ft_strequ(name, tab[index].name))
			return (1);
	}
	return (0);
}
