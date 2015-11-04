/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:44:22 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 23:26:55 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>
# include <macro.h>

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;
typedef struct dirent	*t_dirent;

typedef struct			s_path
{
	char				*str;
	struct s_path		*next;
}						t_path;

typedef struct			s_lex
{
	char				*lex;
	int					flag;
	struct s_lex		*next;
	struct s_lex		*left;
	struct s_lex		*right;
}						t_lex;

typedef struct			s_char
{
	char				c;
	struct s_char		*next;
}						t_char;

typedef struct			s_line
{
	int					id;
	t_char				*line;
	t_char				*tmp;
	int					edit;
	struct s_line		*prev;
	struct s_line		*next;
}						t_line;

typedef struct			s_data
{
	short				run;
	int					max_id;
	t_line				*history;
	t_line				*current;
	int					cur;
	t_lex				*lex;
	char				***envp;
	t_termios			term;
	t_termios			buterm;
	char				buffer[2048];
	int					fd_std[3];
}						t_data;

typedef int				(*t_keys_fn)(char *key);
typedef void			(*t_lex_fn)(t_lex *lex);

#endif
