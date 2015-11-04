/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_wolf3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 03:47:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/19 20:17:16 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <string.h>

# define BUFF_SIZE		4096
# define WIN_X			(320 * 5)
# define WIN_Y			(200 * 5)
# define GRID			4096
# define START_ANGLE	180

# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65634
# define ESC			65307

typedef struct	s_dot
{
	int			x;
	int			y;
	int			a;
}				t_dot;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*imlx;
	int			**map;
	t_dot		map_size;
	double		*cos;
	double		*sin;
	double		*tan;
	int			ray_size;
	int			ray_x;
	t_dot		p;
	int			color;
	int			fov;
	double		disto;
	double		speed;
}				t_env;

void			init_e(t_env *e);
int				draw_img(t_env *e);
double			find_height(t_env *e, double angle, double angle_dist);
int				check_color(int angle, int hor, int ver);
int				key_hook(int keycode, t_env *e);
void			init_p(t_env *e);

void			error(char *s);
size_t			ft_strlen(const char *str);
int				ft_char_int(char c);
int				ft_atoi(const char *str);
double			ft_abs(double x);
double			ft_square(double x);

#endif
