/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:32:00 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 15:33:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindel(char **str1, char **str2)
{
	char	*str;

	str = ft_strjoin(*str1, *str2);
	ft_strdel(str1);
	ft_strdel(str2);
	return (str);
}
