/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:07:39 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/20 19:10:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;

	s = s1;
	while (*s1)
		s1++;
	while (*s2 && (int)n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}
