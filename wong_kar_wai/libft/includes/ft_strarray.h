/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:43:11 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/17 16:43:12 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRARRAY_H
# define FT_STRARRAY_H

void	ft_freearray(char **array, int value);
int		ft_arraylen(char **array);
char	**ft_arraydup(char **array);
#endif
