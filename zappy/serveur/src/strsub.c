/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:30:19 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 11:30:20 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc((len + 1) * sizeof(char));
	strncpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (tmp);
}
