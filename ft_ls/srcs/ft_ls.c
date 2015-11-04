/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:30:53 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 11:22:39 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_error.h"
#include <libft.h>

t_bool	ft_dir_isvalid(t_avl *tmp, char *name)
{
	if (ft_get_file_type(((t_param *)(tmp->content))->st_mode) == 'd')
	{
		if (ft_strcmp("..", name) != 0 && ft_strcmp(".", name) != 0)
			return (TRUE);
	}
	return (FALSE);
}

void	ft_add_file(t_data *data, char *path, t_dirent *ep, t_avl **file)
{
	t_avl	*tmp;
	char	*name;

	name = ep->d_name;
	if ((ft_strchr(data->opts, OPT_A) && *name == '.') || *name != '.')
	{
		tmp = ft_avlnew(ft_param_new(data, path, ep), sizeof(t_param));
		if (ft_strchr(data->opts, OPT_T) != NULL)
			*file = ft_avladd(*file, tmp, &ft_cmp_date);
		else
			*file = ft_avladd(*file, tmp, &ft_cmp_name);
	}
}

void	ft_add_dir(t_data *data, char *path, t_dirent *ep, t_avl **dir)
{
	t_avl	*tmp;
	char	*name;

	name = ep->d_name;
	tmp = ft_avlnew(ft_param_new(data, path, ep), sizeof(t_param));
	if (ft_strchr(data->opts, OPT_REC))
	{
		if (ft_dir_isvalid(tmp, name))
		{
			if (ft_strchr(data->opts, OPT_T) != NULL)
				*dir = ft_avladd(*dir, tmp, &ft_cmp_date);
			else
				*dir = ft_avladd(*dir, tmp, &ft_cmp_name);
		}
	}
}

void	ft_sort_dir(t_data *data, char *param, t_bool alloc, t_bool last)
{
	t_dirent	*ep;
	DIR			*dp;
	t_avl		*dir;
	t_avl		*file;
	t_bool		first_pass;

	init_vars(&dir, &file, &first_pass);
	if ((dp = opendir(param)))
	{
		while ((ep = readdir(dp)) || closedir(dp))
		{
			ft_add_file(data, param, ep, &file);
			ft_add_dir(data, param, ep, &dir);
		}
		ft_print(data, file, alloc ? param : NULL, TRUE);
		if (first_pass && last == FALSE)
		{
			ft_putchar('\n');
			first_pass = FALSE;
		}
	}
	else
		ft_sort_dir_file(data, param);
	ft_sort_dir_end(data, dir, file);
}

void	ft_ls(t_data *data)
{
	int		i;
	char	*params;
	t_bool	last;

	i = 0;
	if (data->nb_params == 0)
		ft_sort_dir(data, CURRENT_DIR, FALSE, TRUE);
	else
	{
		ft_sort_params(data, data->params);
		while (i < data->nb_params)
		{
			last = i == data->nb_params - 1 ? TRUE : FALSE;
			params = ft_strjoin(data->params[i++], "/");
			ft_sort_dir(data, params, TRUE, last);
			ft_strdel(&params);
		}
	}
}
