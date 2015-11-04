/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:49:39 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:39:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <struct.h>

t_lex	*make_lex(char *line, char *op, int len)
{
	t_lex		*oplex;
	t_lex		*lex;

	lex = (t_lex *)malloc(sizeof(t_lex));
	lex->lex = ft_strdup(line + len);
	lex->next = NULL;
	oplex = (t_lex *)malloc(sizeof(t_lex));
	oplex->lex = (char *)malloc(sizeof(char) * len + 1);
	ft_strcpy(oplex->lex, op);
	oplex->next = lex;
	line[0] = '\0';
	oplex->left = NULL;
	oplex->right = NULL;
	lex->left = NULL;
	lex->right = NULL;
	oplex->flag = 0;
	lex->flag = 0;
	return (oplex);
}

char	*make_line(t_char *c)
{
	t_char		*tmp;
	int			len;
	char		*line;

	tmp = c;
	len = 1;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	line = (char *)malloc(sizeof(char) * len);
	line[len - 1] = '\0';
	len = 0;
	while (c)
	{
		line[len++] = c->c;
		c = c->next;
	}
	return (line);
}
