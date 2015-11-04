/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:56:14 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 11:57:07 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>

# include <stdio.h>

# define STDIN			0
# define START			"##start"
# define END			"##end"
# define ERROR			"ERROR"

typedef struct			s_around
{
	struct s_room		*room;
	struct s_around		*next;
}						t_around;

typedef struct			s_ant
{
	int					id;
	t_around			*path;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_room
{
	char				*name;
	int					pos[2];
	int					ants;
	int					pher;
	t_around			*around;
	t_around			*curr;
	struct s_room		*next;
}						t_room;

typedef struct			s_line
{
	char				*line;
	struct s_line		*next;
}						t_line;

typedef struct			s_data
{
	t_line				*file;
	int					ants_nb;
	t_ant				*ants;
	int					state;
	t_room				*rooms;
	t_room				*start;
	int					starting;
	t_room				*end;
}						t_data;

void					read_file(t_data *data);
void					parse_lines(t_data *data);

int						ft_splitlen(char **split);
void					ft_splitdel(char ***split);

void					lem_in(t_data *data);
void					init_ants(t_data *data);

void					error(char *str);

t_room					*add_room(t_data *data, char **split);
void					add_tube(t_data *data, char **split);

int						update_curr(t_room *room);
void					start(t_data *data);
void					display(t_ant *ant, t_room *room);
void					add_path(t_data *data, t_ant *ant, t_room *room);
t_room					*choose(t_data *data, t_room *room);

#endif
