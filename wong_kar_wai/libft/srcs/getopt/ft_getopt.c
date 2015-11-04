/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:52:43 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/23 13:52:44 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_str.h"
#include <stddef.h>

#include "ft_put.h"

t_optvar		*ft_getopt_var(int error, char **argv, char *options)
{
	static t_optvar	option_var = {'\0', -1, NULL, NULL, NULL, NULL};

	if (option_var.error_opt == -1)
		option_var.error_opt = error;
	if (option_var.program_name == NULL)
		option_var.program_name = *argv;
	if (option_var.options == NULL)
		option_var.options = options;
	if (option_var.argv == NULL)
	{
		option_var.argv = argv + 1;
		option_var.letter = *(option_var.argv);
	}
	return (&option_var);
}

static int		ft_getopt_error(t_optvar *var, int c)
{
	var->error_char = c;
	var->letter = *(++(var->argv));
	if (var->error_opt)
	{
		ft_putstr_fd(var->program_name, 2);
		ft_putstr_fd(": illegal option -- ", 2);
		ft_putendl_fd((char*)&c, 2);
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(var->program_name, 2);
		ft_putstr_fd(" [-", 2);
		ft_putstr_fd(var->options, 2);
		ft_putendl_fd("] [file ...]", 2);
	}
	return ('?');
}

char			**ft_getopt_first_nonopt(void)
{
	return ((ft_getopt_var(0, NULL, NULL))->argv);
}

int				ft_getopt(void)
{
	t_optvar	*var;
	char		c;

	var = ft_getopt_var(0, NULL, NULL);
	if (!var->argv || !var->options || !var->letter)
		return (-1);
	if (var->letter == *(var->argv)
		&& (*(var->letter) != '-' || !ft_strcmp(var->letter, "-")))
		return (-1);
	if (var->letter == *(var->argv) && !ft_strcmp(var->letter, "--"))
	{
		var->argv++;
		return (-1);
	}
	if (var->letter == *(var->argv) && (*(var->letter) == '-'))
		var->letter++;
	c = *(var->letter);
	if (ft_strchr(var->options, c))
	{
		var->letter++;
		if (*(var->letter) == 0)
			var->letter = *(++(var->argv));
		return (c);
	}
	return (ft_getopt_error(var, c));
}
