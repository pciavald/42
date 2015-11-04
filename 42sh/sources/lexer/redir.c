/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:54:14 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 16:24:23 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <libft.h>

void		r_redir(t_lex *lex)
{
	int		i;
	char	*str;
	t_lex	*next_lex;
	t_lex	*current;

	current = lex;
	while (current)
	{
		str = current->lex;
		i = -1;
		while (str[++i])
		{
			if (str[i] == '>' && ft_strncmp(str + i, ">>", 2)
				&& (i == 0 || str[i - 1] != '>') && ft_strncmp(str + i, ">&", 2)
				&& ft_strncmp(str + i, ">>&", 3))
			{
				next_lex = make_lex(str + i, ">", 1);
				next_lex->next->next = current->next;
				current->next = next_lex;
				current = current->next;
				break ;
			}
		}
		current = current->next;
	}
}

void		dr_redir(t_lex *lex)
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
			if (ft_strnequ(str + i, ">>", 2) && ft_strncmp(str + i, ">>&", 3))
			{
				next_lex = make_lex(str + i, ">>", 2);
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

void		l_redir(t_lex *lex)
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
			if (str[i] == '<')
			{
				next_lex = make_lex(str + i, "<", 1);
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

void		pipe_redir(t_lex *lex)
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
			if (str[i] == '|' && str[i + 1] != '|'
					&& (i == 0 || str[i - 1] != '|'))
			{
				next_lex = make_lex(str + i, "|", 1);
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
