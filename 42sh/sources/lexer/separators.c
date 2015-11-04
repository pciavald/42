/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:49:58 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 16:24:42 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lexer.h>

void		semicolon(t_lex *lex)
{
	int		i;
	char	*str;
	t_lex	*next_lex;

	i = 0;
	str = lex->lex;
	while (str[i])
	{
		if (str[i] == ';')
		{
			next_lex = make_lex(str + i, ";", 1);
			lex->next = next_lex;
			semicolon(next_lex->next);
			break ;
		}
		i++;
	}
}
