/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:38:39 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/13 23:37:21 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		sh_echo(char **argv, char ***envp)
{
	int		newline;
	int		i;

	(void)envp;
	newline = 1;
	i = 1;
	if (argv[i] && ft_strequ(argv[i], "-n"))
	{
		newline = 0;
		i++;
	}
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (argv[i + 1])
			ft_putchar(' ');
		i++;
	}
	if (newline)
		ft_putchar('\n');
	return (0);
}
