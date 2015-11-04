/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 17:05:08 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 16:23:06 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <libft.h>

void		logic_and(t_lex *lex)
{
	int		i;
	char	*str;
	t_lex	*next_lex;
	t_lex	*current;

	current = lex;
	while (current)
	{
		str = current->lex;
		i = 0;
		while (str[i])
		{
			if (ft_strnequ(str + i, "&&", 2))
			{
				next_lex = make_lex(str + i, "&&", 2);
				next_lex->next->next = current->next;
				current->next = next_lex;
				current = current->next;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void		logic_or(t_lex *lex)
{
	int		i;
	char	*str;
	t_lex	*next_lex;
	t_lex	*current;

	current = lex;
	while (current)
	{
		str = current->lex;
		i = 0;
		while (str[i])
		{
			if (ft_strnequ(str + i, "||", 2))
			{
				next_lex = make_lex(str + i, "||", 2);
				next_lex->next->next = current->next;
				current->next = next_lex;
				current = current->next;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
