/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:16:35 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/13 16:18:23 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** put_env() takes an environnement array and writes it to the standard output
*/
#include <libft.h>

void	put_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
}
