/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:39:23 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:39:08 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <struct.h>

void	parser(t_lex *lex);
t_lex	*parse_redir(t_lex *lex, int min, int max);

#endif
