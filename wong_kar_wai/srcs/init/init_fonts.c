/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fonts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:04:47 by pciavald          #+#    #+#             */
/*   Updated: 2015/03/01 21:22:19 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include "fonts.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void		append(t_font *font, short current, char *line, int fd)
{
	int			size;

	if (current == 0)
	{
		font->img_width = ft_atoi(line);
		line = NULL;
		get_next_line(fd, &line);
		font->img_height = ft_atoi(line);
		return ;
	}
	current -= 1;
	size = BUFFSIZE - (ft_strlen(font->img[current]) + ft_strlen(line) + 2);
	if (size < 0)
		error(ERRIMG, line, EXIT);
	ft_strncat(font->img[current], line, size);
	ft_strncat(font->img[current], "\n", 1);
}

static char		*make_path(char *rsc_path, char *rsc_dir, char *rsc_file)
{
	char		*path;
	int			size;

	size = ft_strlen(rsc_path) + ft_strlen(rsc_dir) + ft_strlen(rsc_file) + 2;
	path = (char *)malloc(sizeof(char) * size);
	ft_memset(path, '\0', size);
	ft_strncat(path, rsc_path, ft_strlen(rsc_path));
	ft_strncat(path, rsc_dir, ft_strlen(rsc_dir));
	ft_strncat(path, "/", 1);
	ft_strncat(path, rsc_file, ft_strlen(rsc_file));
	return (path);
}

static t_bool	is_file(t_dirent *entry)
{
	return (entry->d_type == DT_REG);
}

static DIR		*open_rsc(t_font *font)
{
	char		path[BUFFSIZE];
	DIR			*dirp;

	ft_bzero(path, BUFFSIZE);
	ft_strncat(path, RSC_DIR, ft_strlen(RSC_DIR));
	ft_strncat(path, font->img_type, sizeof(path) - ft_strlen(path));
	if ((dirp = opendir(path)) == NULL)
		error(ERROPEN, path, EXIT);
	return (dirp);
}

void			load_images(t_font *font)
{
	DIR			*dirp;
	t_dirent	*entry;
	int			fd;
	char		*line;

	font->img_type = FONT;
	dirp = open_rsc(font);
	while ((entry = readdir(dirp)))
	{
		if (is_file(entry))
		{
			line = make_path(RSC_DIR, font->img_type, entry->d_name);
			if ((fd = open(line, O_RDONLY)) < 0)
				error(ERROPEN, line, EXIT);
			ft_strdel(&line);
			while (get_next_line(fd, &line))
			{
				append(font, ft_atoi(entry->d_name), line, fd);
				ft_strdel(&line);
			}
			close(fd);
		}
	}
	closedir(dirp);
}
