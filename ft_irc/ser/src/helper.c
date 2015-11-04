/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 21:23:44 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:09:41 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int		check_nick(char **cmd)
{
	if (ft_countsplit(cmd) != 2)
		return (0);
	if (ft_strlen(cmd[1]) > 9)
		return (0);
	if (ft_strlen(cmd[1]) == 0)
		return (0);
	if (!ft_isprintnstr(cmd[1], ft_strlen(cmd[1]) - 1))
		return (0);
	if (!ft_isprint(cmd[1][0]))
		return (0);
	return (1);
}

int		check_chan(char **cmd)
{
	if (ft_countsplit(cmd) != 2)
		return (0);
	if (ft_strlen(cmd[1]) > 50)
		return (0);
	if (ft_strlen(cmd[1]) == 0)
		return (0);
	if (!ft_isprintnstr(cmd[1], ft_strlen(cmd[1]) - 1))
		return (0);
	return (1);
}

int		check_msg(char **cmd)
{
	if (ft_countsplit(cmd) != 3)
		return (0);
	if (ft_strlen(cmd[1]) > 9)
		return (0);
	if (ft_strlen(cmd[1]) == 0)
		return (0);
	if (ft_strlen(cmd[2]) > BUF_SIZE)
		return (0);
	if (ft_strlen(cmd[2]) == 0)
		return (0);
	if (!ft_isprintnstr(cmd[1], ft_strlen(cmd[1]) - 1))
		return (0);
	return (1);
}

int		is_valid(char **split, int opt)
{
	if (opt == 1)
		return (check_nick(split));
	if (opt == 2)
		return (check_chan(split));
	if (opt == 3)
		return (check_msg(split));
	return (0);
}
