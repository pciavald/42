/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:34:29 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 06:44:45 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_error.h"
#include <libft.h>

t_data		*ft_eval_option(char *s, t_data *data, int *opt)
{
	while (*(++s))
	{
		if (ft_strchr(OPTS, *s))
		{
			if (ft_strchr(data->opts, *s) == NULL)
			{
				data->opts[*opt] = *s;
				*opt = *opt + 1;
			}
		}
		else
			ft_error(ILLEGAL_OPTION, OPT_ERROR, s, TRUE);
	}
	return (data);
}

t_data		*load_options(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		st;
	int		opt;

	i = 1;
	st = 1;
	opt = 0;
	while (st < argc && argv[st][0] == OPT_START && argv[st][1] != '\0')
		st++;
	if (!(data = ft_data_new(argc - st)))
		ft_error(NOT_ENOUGH_MEM, STR_ERROR, "", TRUE);
	while (i < argc && argv[i][0] == OPT_START && argv[i][1] != '\0')
		data = ft_eval_option(argv[i++], data, &opt);
	while (i < argc)
	{
		data->params[i - st] = ft_strdup(argv[i]);
		i++;
	}
	return (data);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	data = load_options(argc, argv);
	ft_ls(data);
	if (data)
		ft_data_del(data);
	return (0);
}
