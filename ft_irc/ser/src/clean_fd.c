/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:10:07 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 21:02:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bircd.h"

void	clean_fd(t_fd *fd)
{
	fd->i = 0;
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	ft_bzero(fd->nickname, 10);
	ft_bzero(fd->channel, 50);
}
