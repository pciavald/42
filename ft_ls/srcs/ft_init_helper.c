/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:29:44 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 09:07:17 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

void	ft_data_del(t_data *data)
{
	int		i;

	i = -1;
	if (data->params != NULL)
	{
		while (++i < data->nb_params)
			free(data->params[i]);
		free(data->params);
	}
	free(data);
	data = NULL;
}

t_data	*ft_data_new(int nb_params)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->params = (char **)malloc(sizeof(char *) * (nb_params + 1))))
		return (NULL);
	data->params[nb_params] = NULL;
	data->nb_params = nb_params;
	return (data);
}

t_param	*ft_param_new(t_data *data, char *path, t_dirent *ep)
{
	t_param		*param;
	t_stat		file_stat;
	char		*tmp;
	char		*tmp2;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->name = ft_strdup(ep->d_name);
	tmp2 = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp2, ep->d_name);
	free(tmp2);
	if (lstat(tmp, &file_stat) < 0)
		perror(tmp);
	else
		param_h(data, &param, &file_stat, ep);
	free(tmp);
	return (param);
}

void	param_h(t_data *data, t_param **p, t_stat *file_stat, t_dirent *ep)
{
	(*p)->st_mode = file_stat->st_mode;
	(*p)->tv_sec = file_stat->st_mtimespec.tv_sec;
	(*p)->st_nlink = file_stat->st_nlink;
	(*p)->d_type = ep->d_type;
	if (ft_strchr(data->opts, OPT_L))
	{
		(*p)->user = getpwuid((file_stat->st_uid))
			? getpwuid(file_stat->st_uid)->pw_name
			: ft_itoa(file_stat->st_uid);
		(*p)->group = getgrgid(file_stat->st_gid)
			? getgrgid(file_stat->st_gid)->gr_name
			: ft_itoa(file_stat->st_gid);
		(*p)->st_size = file_stat->st_size;
		(*p)->st_blocks = file_stat->st_blocks;
		(*p)->st_rdev = file_stat->st_rdev;
	}
}
