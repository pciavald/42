/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bircd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:09:57 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 21:44:59 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIRCD_H
# define BIRCD_H

# include <sys/select.h>
# include <libft.h>
# include <struct.h>

# define FD_FREE			0
# define FD_SERV			1
# define FD_CLIENT			2

# define XV(err,res,str)	(x_void(err,res,str))
# define X(err,res,str)		(x_int(err,res,str))
# define MAX(a,b)			((a > b) ? a : b)

# define USAGE				"Usage: %s port\n"
# define BUF_SIZE			4096

typedef struct				s_fd
{
	int						type;
	void					(*fct_read)();
	void					(*fct_write)();
	int						i;
	char					buf_read[BUF_SIZE + 1];
	char					buf_write[BUF_SIZE + 1];
	char					nickname[10];
	char					channel[50];
}							t_fd;

typedef struct				s_env
{
	t_fd					*fds;
	int						port;
	int						maxfd;
	int						max;
	int						r;
	fd_set					fd_read;
	fd_set					fd_write;
}							t_env;

void						init_env(t_env *e);
void						get_opt(t_env *e, int ac, char **av);
void						main_loop(t_env *e);
void						srv_create(t_env *e, int port);
void						srv_accept(t_env *e, int s);
void						client_read(t_env *e, int cs);
void						client_write(t_env *e, int cs);
void						clean_fd(t_fd *fd);
int							x_int(int err, int res, char *str);
void						*x_void(void *err, void *res, char *str);
void						init_fd(t_env *e);
void						do_select(t_env *e);
void						check_fd(t_env *e);
void						s_info(t_env *e, char *nm, char *info, char *chan);
void						parse(t_env *e, int cs, char *cmd);
void						change_nickname(t_env *e, int cs, char **cmd);
void						join_channel(t_env *e, int cs, char **cmd);
void						leave_channel(t_env *e, int cs, char **cmd);
void						who(t_env *e, int cs);
void						pmessage(t_env *e, int cs, char **cmd);
int							is_valid(char **split, int opt);

#endif
