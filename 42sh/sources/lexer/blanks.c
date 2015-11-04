/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:26:39 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 18:19:43 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <libft.h>
#include <stdlib.h>

static int		new_len(char *str)
{
	int			i;
	int			len;
	int			spaced;

	i = 0;
	len = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			len++;
			spaced = 0;
		}
		else if (!spaced)
		{
			len++;
			spaced = 1;
		}
		i++;
	}
	return (len);
}

static void		str_trimcpy(char *dest, char *src, int len)
{
	int			i;
	int			spaced;

	i = 0;
	while (*src && (*src == ' ' || *src == '\t'))
		src++;
	while (len)
	{
		if (*src != ' ' && *src != '\t')
		{
			dest[i++] = *src;
			len--;
			spaced = 0;
		}
		else if (!spaced)
		{
			dest[i++] = ' ';
			len--;
			spaced = 1;
		}
		src++;
	}
	dest[i] = '\0';
}

void			blanks(t_lex *lex)
{
	char		*str;
	int			len;

	while (lex)
	{
		str = lex->lex;
		len = new_len(str);
		lex->lex = (char *)malloc(sizeof(char) * (len + 1));
		str_trimcpy(lex->lex, str, len);
		free(str);
		lex = lex->next;
	}
}
