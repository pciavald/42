/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:37:36 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:36:05 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <libft.h>

#define FLAGS		11

int			is_unsupported(char *str)
{
	if (ft_strnequ(str, "<<", 2))
		return (5);
	else if (ft_strnequ(str, "|&", 2))
		return (7);
	return (0);
}

void		dr_redir_amp(t_lex *lex)
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
			if (ft_strnequ(str + i, ">>&", 3))
			{
				next_lex = make_lex(str + i, ">>&", 3);
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

void		r_redir_amp(t_lex *lex)
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
			if (ft_strnequ(str + i, ">&", 2) && (i == 0 || str[i - 1] != '>'))
			{
				next_lex = make_lex(str + i, ">&", 2);
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

static void	init_tab(char flags[FLAGS][4])
{
	ft_strcpy(flags[0], ";");
	ft_strcpy(flags[1], "||");
	ft_strcpy(flags[2], "&&");
	ft_strcpy(flags[3], "<");
	ft_strcpy(flags[4], "<<");
	ft_strcpy(flags[5], "|");
	ft_strcpy(flags[6], "|&");
	ft_strcpy(flags[7], ">");
	ft_strcpy(flags[8], ">&");
	ft_strcpy(flags[9], ">>");
	ft_strcpy(flags[10], ">>&");
}

int			other(t_lex *lex)
{
	t_lex	*current;
	int		i;
	int		ret;
	char	flags[FLAGS][4];

	init_tab(flags);
	current = lex;
	while (current)
	{
		i = 0;
		while (current->lex[i])
		{
			if ((ret = is_unsupported(current->lex + i)))
			{
				ft_printf_fd(2, "42sh: invalid operand: %s\n", flags[ret - 1]);
				return (1);
			}
			i++;
		}
		current = current->next;
	}
	return (0);
}
