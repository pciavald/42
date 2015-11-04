/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:08:49 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 20:45:33 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>
#include <helpers.h>
#include <libft.h>
#include <parser.h>
#include <proto.h>
#include <stdlib.h>
#include <struct.h>

#define FLAGS		11

int				g_parse_error;

static void		init_tab(char flags[FLAGS][4])
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

static int		check_lex(t_lex *lex)
{
	if (lex->flag == 2 || lex->flag == 3 || lex->flag == 6 || lex->flag == 7)
	{
		if (!lex->left || lex->left->lex[0] == '\0'
				|| !lex->right || lex->right->lex[0] == '\0')
		{
			ft_printf_fd(2, "42sh: syntax error near token '%s'\n", lex->lex);
			g_parse_error = 1;
			return (-1);
		}
	}
	return (0);
}

static void		flag_lex(t_lex *lex)
{
	int			i;
	char		flags[FLAGS][4];

	init_tab(flags);
	while (lex)
	{
		i = 0;
		lex->flag = 0;
		while (i < FLAGS)
		{
			if (ft_strequ(flags[i++], lex->lex))
				lex->flag = i;
		}
		lex = lex->next;
	}
}

static t_lex	*parse(t_lex *lex, int min, int max)
{
	t_lex		*search;

	if (lex && lex->flag)
	{
		lex->left = parse(lex->left, min, max);
		lex->right = parse(lex->right, min, max);
		return (lex);
	}
	search = lex;
	while (search && (search->flag < min || search->flag > max))
		search = search->next;
	if (search)
	{
		search->left = lex;
		while (lex->next != search)
			lex = lex->next;
		lex->next = NULL;
		search->right = parse(search->next, min, max);
		search->next = NULL;
		check_lex(search);
		return (search);
	}
	return (lex);
}

void			parser(t_lex *lex)
{
	g_parse_error = 0;
	flag_lex(lex);
	lex = parse(lex, 1, 1);
	lex = parse(lex, 2, 3);
	lex = parse_redir(lex, 4, 5);
	lex = parse(lex, 6, 7);
	lex = parse_redir(lex, 8, 11);
	if (lex && g_parse_error == 0)
		exec_lex(lex, data()->envp, NULL, NULL);
	free_lex(lex);
}
