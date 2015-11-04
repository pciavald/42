/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_simplifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 01:07:41 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 23:25:00 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** This function simplify path according to the cd -I needs.
*/

#include <helpers.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>

static void	add_path(t_path **path_list, char *path)
{
	t_path	*path_nod;
	t_path	*current;

	path_nod = (t_path *)malloc(sizeof(t_path));
	path_nod->str = path;
	path_nod->next = NULL;
	if (*path_list)
	{
		current = *path_list;
		while (current->next)
			current = current->next;
		current->next = path_nod;
	}
	else
		*path_list = path_nod;
}

static char	*rebuild_path(t_path *path_list)
{
	t_path	*current;
	char	*path;
	int		len;

	current = path_list;
	len = 0;
	while (current)
	{
		len += ft_strlen(current->str) + 1;
		current = current->next;
	}
	path = (char *)malloc(sizeof(char) * (len + 1));
	current = path_list;
	len = 0;
	while (current)
	{
		ft_strcpy(path + len, "/");
		ft_strcpy(path + len + 1, current->str);
		current = current->next;
		len = ft_strlen(path);
	}
	return (path);
}

static void	remove_dot(t_path **path_list)
{
	t_path	*tmp;
	t_path	*current;

	if (*path_list && ft_strequ((*path_list)->str, "."))
	{
		free((*path_list)->str);
		tmp = (*path_list)->next;
		free(*path_list);
		*path_list = tmp;
	}
	current = *path_list;
	while (current && current->next)
	{
		if (ft_strequ(current->next->str, "."))
		{
			free(current->next->str);
			tmp = current->next->next;
			free(current->next);
			current->next = tmp;
		}
		else
			current = current->next;
	}
}

static int	remove_dotdot(t_path **path_list, t_path *current)
{
	t_path	*tmp;
	int		modif;

	modif = 0;
	while (current && ft_strcmp(current->str, "..")
			&& current->next && ft_strequ(current->next->str, ".."))
	{
		modif++;
		tmp = current->next->next;
		free(current->next->str);
		free(current->next);
		free(current->str);
		free(current);
		*path_list = tmp;
		current = tmp;
	}
	while (current && current->next)
	{
		modif += remove_dotdot(&current->next, current->next);
		current = current->next;
	}
	if (modif)
		remove_dotdot(path_list, *path_list);
	return (modif);
}

char		*path_simplifier(char *path)
{
	int		i;
	int		len;
	t_path	*path_list;

	i = 0;
	path_list = NULL;
	while (path[i])
	{
		len = 0;
		while (path[i] && path[i] == '/')
			i++;
		while (path[i + len] && path[i + len] != '/')
			len++;
		add_path(&path_list, ft_strsub(path, i, len));
		i += len;
	}
	remove_dot(&path_list);
	remove_dotdot(&path_list, path_list);
	free(path);
	path = rebuild_path(path_list);
	free_pathlist(path_list);
	return (path);
}
