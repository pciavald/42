/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:45:18 by fcorre            #+#    #+#             */
/*   Updated: 2014/06/12 14:19:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_error(char *str)
{
	if (str)
		fprintf(stderr, "Zappy: %s error\n", str);
	else
		fprintf(stderr, "Zappy: error");
	exit(1);
}
