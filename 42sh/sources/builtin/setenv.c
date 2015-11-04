/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:11:24 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/13 21:47:17 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>

int		sh_setenv(char **argv, char ***env)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
		put_env(*env);
	else if (i == 2)
		set_envline(argv[1], "", env);
	else if (i == 3)
		set_envline(argv[1], argv[2], env);
	else
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		return (-1);
	}
	return (0);
}
