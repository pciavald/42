/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 04:39:22 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/22 04:53:18 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <helpers.h>
#include <libft.h>

int		sh_exit(char **argv, char ***envp)
{
	int		i;

	(void)envp;
	if (argv[1])
	{
		if (argv[2])
		{
			ft_putendl("42sh: exit: too many arguments");
			return (-1);
		}
		i = -1;
		if (argv[1][i + 1] == '-' || argv[1][i + 1] == '+')
			i++;
		while (argv[1][++i])
		{
			if (!ft_isdigit(argv[1][i]))
			{
				ft_putendl("42sh: exit: numeric argument required");
				return (-1);
			}
		}
		quit(NULL, ft_atoi(argv[1]));
	}
	quit(NULL, 0);
	return (0);
}
