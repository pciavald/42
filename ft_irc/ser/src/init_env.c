/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:11:36 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 14:25:25 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include "bircd.h"

void		init_env(t_env *e)
{
	int				i;
	struct rlimit	rlp;

	X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)XV(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
	i = 0;
	while (i < e->maxfd)
	{
		clean_fd(&e->fds[i]);
		i++;
	}
}
