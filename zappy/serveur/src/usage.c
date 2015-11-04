/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 14:49:45 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void	check_opt(t_data *data)
{
	if (data->port == -1
			|| data->x == -1
			|| data->y == -1
			|| data->teams == NULL
			|| data->max_clients == -1
			|| data->time == -1)
		usage(data->name);
}

void	usage(char *str)
{
	fprintf(stderr, "Usage: %s -p <port> -x <width> -y <height>", str);
	fprintf(stderr, " -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	fprintf(stderr, "-p numero de port\n");
	fprintf(stderr, "-x largeur du Monde\n");
	fprintf(stderr, "-y hauteur du Monde\n");
	fprintf(stderr, "-n nom\\_equipe\\_1 nom\\_\\_equipe_2 ...\n");
	fprintf(stderr, "-c nombre de client autorises au commencement du jeu\n");
	fprintf(stderr, "-t diviseur de l'unite de temps (plus t est grand,");
	fprintf(stderr, "plus le jeu va vite)\n");
	exit(-1);
}
