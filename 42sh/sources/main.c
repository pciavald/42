/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:16:41 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 22:52:02 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <macro.h>
#include <prompt.h>
#include <proto.h>
#include <struct.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (!getenv("TERM"))
	{
		write(2, "Empty environment\n", 18);
		return (1);
	}
	init(envp);
	read_line();
	return (0);
}

t_data	*data(void)
{
	static t_data		*data = NULL;

	if (data == NULL)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->history = NULL;
		data->max_id = 1;
		data->current = NULL;
		data->cur = NONE;
		data->run = 0;
		data->fd_std[0] = dup(0);
		data->fd_std[1] = dup(1);
		data->fd_std[2] = dup(2);
	}
	return (data);
}
