/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:28:18 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 11:23:19 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <unistd.h>

void	ft_print(t_data *data, t_avl *head, char *param, t_bool isdir)
{
	int		len[5];

	init_len(len);
	if (param && data->nb_params > 1)
	{
		param[ft_strlen(param) - 1] = '\0';
		ft_putstr(param);
		ft_putendl(":");
	}
	if (!ft_strchr(data->opts, OPT_L))
	{
		if (ft_strchr(data->opts, OPT_REV))
			ft_avliter_inorderrev(head, &ft_print_param);
		else
			ft_avliter_inorder(head, &ft_print_param);
		return ;
	}
	if (!head)
		return ;
	ft_print_helper(head, len, isdir);
	if (ft_strchr(data->opts, OPT_REV))
		ft_print_ls_rev(head, len);
	else
		ft_print_ls(head, len);
}

void	ft_print_helper(t_avl *head, int len[5], t_bool isdir)
{
	ft_get_size(head, &len[4]);
	ft_max_len_link(head, &len[0]);
	ft_max_len_user(head, &len[1]);
	ft_max_len_group(head, &len[2]);
	ft_max_len_size(head, &len[3]);
	len[0] = ft_intlen(len[0]);
	len[3] = ft_intlen(len[3]);
	if (isdir)
	{
		ft_putstr("total ");
		ft_putnbr(len[4]);
		ft_putchar('\n');
	}
}

void	ft_print_full_param(t_avl *head, int len[4])
{
	t_param		*param;
	char		link[256];

	param = (t_param *)head->content;
	ft_print_param_l(param);
	ft_print_link(param, len[0]);
	ft_print_user(param, len[1]);
	ft_print_group(param, len[2]);
	ft_print_size(param, len[3]);
	ft_print_time(param->tv_sec);
	ft_putstr(param->name);
	if (param->d_type == DT_LNK)
	{
		ft_putstr(" -> ");
		ft_memset((void *)link, '\0', 256);
		readlink(param->name, link, 256);
		ft_putstr(link);
	}
	ft_putchar('\n');
}

void	ft_print_ls(t_avl *head, int len[4])
{
	if (!head)
		return ;
	ft_print_ls(head->left, len);
	ft_print_full_param(head, len);
	ft_print_ls(head->right, len);
}

void	ft_print_ls_rev(t_avl *head, int len[4])
{
	if (!head)
		return ;
	ft_print_ls_rev(head->right, len);
	ft_print_full_param(head, len);
	ft_print_ls_rev(head->left, len);
}
