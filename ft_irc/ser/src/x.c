/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:14:30 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/24 15:37:09 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bircd.h"

int		x_int(int err, int res, char *str)
{
	if (res == err)
	{
		fprintf(stderr, "%s error : %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str)
{
	if (res == err)
	{
		fprintf(stderr, "%s error : %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}
