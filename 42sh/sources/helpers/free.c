/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:44:16 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 23:26:50 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <stdlib.h>

void	free_lex(t_lex *lex)
{
	if (lex)
	{
		free_lex(lex->left);
		free_lex(lex->right);
		if (lex->lex)
			free(lex->lex);
		free(lex);
	}
}

void	free_pathlist(t_path *list)
{
	t_path	*prev;

	while (list)
	{
		prev = list;
		list = list->next;
		free(prev->str);
		free(prev);
	}
}
