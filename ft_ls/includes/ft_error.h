/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:21:14 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 07:16:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "ft_ls.h"

# define STR_ERROR	1
# define OPT_ERROR	2
# define PERROR		3

# define NOT_ENOUGH_MEM	12
# define NO_SUCH_FILE	2
# define ILLEGAL_OPTION	0

void	ft_error(int num_error, int type_error, char *param, t_bool b_exit);
void	ft_error_illegal_option(char *param);

#endif
