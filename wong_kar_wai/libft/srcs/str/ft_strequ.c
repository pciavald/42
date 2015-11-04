/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:08 by tcharlat          #+#    #+#             */
/*   Updated: 2014/02/09 05:28:37 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strequ(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (*tmp1 == *tmp2)
	{
		if (!*tmp1)
			return (1);
		tmp1++;
		tmp2++;
	}
	return (0);
}
