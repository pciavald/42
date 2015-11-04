/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:29:02 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/24 20:37:10 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include <libft.h>
#include <stdio.h>

void	ft_error(int num_error, int type_error, char *param, t_bool b_exit)
{
	if (type_error == STR_ERROR)
	{
		ft_putstr("ls: ");
		ft_putstr(param);
		ft_putstr(": ");
		ft_putstr(strerror(num_error));
		ft_putchar('\n');
	}
	else if (type_error == OPT_ERROR)
		ft_error_illegal_option(param);
	else if (type_error == PERROR)
	{
		ft_putstr("ls: ");
		param[ft_strlen(param) - 1] = '\0';
		perror(param);
	}
	if (b_exit)
		exit(EXIT_FAILURE);
}

void	ft_error_illegal_option(char *param)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*param);
	ft_putchar('\n');
	ft_putstr("usage: ls [-");
	ft_putchar(OPT_A);
	ft_putchar(OPT_L);
	ft_putchar(OPT_REC);
	ft_putchar(OPT_REV);
	ft_putchar(OPT_T);
	ft_putstr("] [file ...]\n");
}
