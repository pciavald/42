/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:52:11 by tcharlat          #+#    #+#             */
/*   Updated: 2015/02/23 13:52:12 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

typedef struct	s_optvar
{
	int			error_char;
	int			error_opt;
	char		*program_name;
	char		**argv;
	char		*options;
	char		*letter;
}				t_optvar;

int				ft_getopt(void);
char			**ft_getopt_first_nonopt(void);
t_optvar		*ft_getopt_var(int error, char **argv, char *options);
#endif
