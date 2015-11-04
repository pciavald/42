/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 22:21:48 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 11:22:41 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_error.h"
#include "libft.h"
#include <dirent.h>

void	init_vars(t_avl **dir, t_avl **file, t_bool *first_pass)
{
	*dir = NULL;
	*file = NULL;
	*first_pass = TRUE;
}

void	init_len(int len[5])
{
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	len[4] = 0;
}

void	ft_sort_dir_file(t_data *data, char *param)
{
	DIR			*dp;
	t_dirent	*ep;
	t_avl		*file;

	file = NULL;
	param[ft_strlen(param) - 1] = '\0';
	if ((dp = opendir(CURRENT_DIR)))
	{
		while ((ep = readdir(dp)))
		{
			if (ft_strcmp(ep->d_name, param) == 0)
				break ;
		}
		closedir(dp);
		if (ep != NULL)
		{
			strncpy(ep->d_name, param, 256);
			ft_add_file(data, CURRENT_DIR, ep, &file);
		}
		else
			ft_error(-1, PERROR, param, FALSE);
		ft_print(data, file, param, FALSE);
	}
	else
		ft_error(-1, PERROR, param, FALSE);
}

void	ft_sort_dir_end(t_data *data, t_avl *dir, t_avl *file)
{
	if (file)
		ft_avldel(&file, &ft_param_del);
	if (ft_strchr(data->opts, OPT_REC))
		ft_recursive(data, dir);
	if (dir)
		ft_avldel(&dir, &ft_param_del);
}

void	ft_sort_params(t_data *d, char **p)
{
	char		*swap;
	int			a;
	int			b;
	int			n;

	n = d->nb_params;
	a = 1;
	swap = NULL;
	while (a < n)
	{
		b = 0;
		while (b < a - 1)
		{
			if ((ft_strchr(d->opts, OPT_REV) && ft_strcmp(p[b], p[b + 1]) > 0))
			{
				swap = p[b];
				p[b] = p[b + 1];
				p[b + 1] = swap;
			}
			b++;
		}
		a++;
	}
}
