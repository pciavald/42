/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:40:48 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 21:41:41 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <helpers.h>
#include <libft.h>
#include <proto.h>
#include <prompt.h>
#include <stdlib.h>

static void		clean_lines(void)
{
	t_line	*tmp;
	t_line	*prev;

	tmp = data()->history;
	while (tmp)
	{
		tmp->line = del_str(tmp->line);
		tmp->tmp = del_str(tmp->tmp);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	tmp = data()->current;
	if (tmp)
	{
		tmp->line = del_str(tmp->line);
		tmp->tmp = del_str(tmp->tmp);
		free(tmp);
	}
}

void			quit(char *str, int status)
{
	if (str)
		ft_putstr(str);
	clean_lines();
	free_split(*data()->envp);
	free(data());
	exit(status);
}
