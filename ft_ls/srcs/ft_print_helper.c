/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:32:28 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 10:58:09 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <time.h>

void	ft_print_link(t_param *param, int len_link)
{
	ft_print_space(ft_intlen(param->st_nlink), len_link);
	ft_putnbr(param->st_nlink);
	ft_putchar(' ');
}

void	ft_print_size(t_param *param, int len_size)
{
	char	c;

	c = ft_get_file_type(param->st_mode);
	if (c == 'b' || c == 'c')
	{
		ft_print_space(ft_intlen(MAJOR(param->st_rdev)), 3);
		ft_putnbr(MAJOR(param->st_rdev));
		ft_putstr(", ");
		ft_print_space(ft_intlen(MINOR(param->st_rdev)), 3);
		ft_putnbr(MINOR(param->st_rdev));
	}
	else
	{
		ft_print_space(ft_intlen(param->st_size), len_size);
		ft_putnbr(param->st_size);
	}
	ft_putchar(' ');
}

void	ft_print_user(t_param *param, int len_name)
{
	ft_putstr(param->user);
	ft_print_space(ft_strlen(param->user), len_name);
	ft_putstr("  ");
}

void	ft_print_group(t_param *param, int len_group)
{
	ft_putstr(param->group);
	ft_print_space(ft_strlen(param->group), len_group);
	ft_putstr("  ");
}

void	ft_print_time(time_t timestamp)
{
	char	*stime;
	char	**split;
	int		i;

	stime = ctime(&timestamp);
	split = ft_strsplit(stime, ' ');
	ft_putstr(split[1]);
	ft_putchar(' ');
	if (ft_strlen(split[2]) == 1)
		ft_putchar(' ');
	ft_putstr(split[2]);
	ft_putchar(' ');
	if (ABS(time(NULL) - timestamp) < 15778463)
		ft_putstr((stime = ft_strsub(split[3], 0, 5)));
	else
	{
		ft_putchar(' ');
		ft_putstr((stime = ft_strsub(split[4], 0, 4)));
	}
	ft_strdel(&stime);
	ft_putchar(' ');
	i = 0;
	while (i <= 4)
		ft_strdel(&split[i++]);
	free(split);
}
