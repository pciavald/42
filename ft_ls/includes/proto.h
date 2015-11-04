/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 07:17:23 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 10:41:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <sys/stat.h>
# include <stdlib.h>
# include <libft.h>
# include <dirent.h>

# define CURRENT_DIR		"."
# define HIDE_FILE			'.'
# define WILD_CARD			'*'
# define OPT_START			'-'
# define NB_OPTS			7
# define OPTS				"Raltr1-"
# define OPT_REC			'R'
# define OPT_A				'a'
# define OPT_L				'l'
# define OPT_T				't'
# define OPT_REV			'r'
# define OPT_ONE			'1'
# define OPT_END			'-'

# define FALSE				0
# define TRUE				1

# define MINORBITS			20
# define MINORMASK			((1U << MINORBITS) - 1)
# define MAJOR(dev)			((unsigned int) ((dev) >> (MINORBITS + 4)))
# define MINOR(dev)			((unsigned int) ((dev) & MINORMASK))
# define ABS(x)				((x) > 0 ? (x) : -(x))

typedef int					t_bool;
typedef struct stat			t_stat;
typedef struct dirent		t_dirent;
typedef struct timespec		t_timespec;

typedef struct				s_data
{
	char					**params;
	int						nb_params;
	char					opts[NB_OPTS];
}							t_data;

typedef struct				s_param
{
	char					*name;
	char					*user;
	char					*group;
	mode_t					st_mode;
	nlink_t					st_nlink;
	off_t					st_size;
	time_t					tv_sec;
	blkcnt_t				st_blocks;
	dev_t					st_rdev;
	unsigned char			d_type;
}							t_param;

#endif
