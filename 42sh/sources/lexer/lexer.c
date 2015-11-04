/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:37:08 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:20:11 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <libft.h>
#include <parser.h>
#include <proto.h>
#include <stdlib.h>

static void		init_tab(t_lex_fn *t_tab)
{
	t_tab[0] = semicolon;
	t_tab[1] = dr_redir_amp;
	t_tab[2] = r_redir_amp;
	t_tab[3] = logic_and;
	t_tab[4] = logic_or;
	t_tab[5] = dr_redir;
	t_tab[6] = r_redir;
	t_tab[7] = l_redir;
	t_tab[8] = pipe_redir;
}

void			lexer(t_char *line)
{
	t_lex_fn	fn_tab[LEX];
	short		count;
	t_lex		*lex;

	lex = (t_lex *)malloc(sizeof(t_lex));
	lex->lex = make_line(line);
	lex->next = NULL;
	lex->right = NULL;
	lex->left = NULL;
	lex->flag = 0;
	data()->lex = lex;
	count = 0;
	init_tab(fn_tab);
	if (other(data()->lex))
		return ;
	while (count < LEX)
		fn_tab[count++](data()->lex);
	blanks(data()->lex);
	parser(data()->lex);
}
