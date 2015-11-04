/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:31:43 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 23:01:30 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <struct.h>
#include <stdlib.h>
#include <parser.h>

static t_lex	*parse_redir2(t_lex *lex, t_lex *search, int min, int max)
{
	int			i;
	char		*tmp;

	free(lex->lex);
	i = 0;
	while (search->next->lex[i] && search->next->lex[i] != ' ')
		i++;
	search->left = lex;
	lex->next = NULL;
	search->left->lex = ft_strsub(search->next->lex, 0, i);
	tmp = search->next->lex;
	search->next->lex = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i + 1);
	free(tmp);
	search->right = parse_redir(search->next, min, max);
	search->next = NULL;
	return (search);
}

t_lex			*parse_redir(t_lex *lex, int min, int max)
{
	t_lex		*search;

	if (lex && lex->flag)
	{
		lex->left = parse_redir(lex->left, min, max);
		lex->right = parse_redir(lex->right, min, max);
	}
	else
	{
		search = lex;
		while (search && (search->flag < min || search->flag > max))
			search = search->next;
		if (search && ft_strequ(lex->lex, ""))
			return (parse_redir2(lex, search, min, max));
		else if (search)
		{
			search->left = search->next;
			search->next = NULL;
			lex->next = search->left->next;
			search->left->next = NULL;
			search->right = parse_redir(lex, min, max);
			return (search);
		}
	}
	return (lex);
}
