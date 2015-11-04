/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:57:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 22:15:27 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/select.h>
# include <string.h>

# define FD_FREE		0
# define FD_SERV		1
# define FD_CLIENT		2
# define FD_PLAYER		3
# define FD_GUI			4

# define BUF_SIZE		2048
# define TIMEOUT_S		0
# define TIMEOUT_US		0

# define N				1
# define E				2
# define S				3
# define W				4

# define CMD_NB			12
# define GCMD_NB		9

# define MOVE_T			7
# define LOOK_T			7
# define INV_T			1
# define TAKE_T			7
# define DROP_T			7
# define PUSH_T			7
# define BCAST_T		7
# define INCANT_T		300
# define FORK_T			42
# define FOOD_T			126
# define BIRTH_T		600

# define START			0
# define END			1

# define SQUARE(X)		(X) * (X)

typedef struct timeval	t_timeval;
typedef struct s_data	t_data;

typedef struct			s_egg
{
	int					id;
	int					owner;
	char				*team;
	int					food;
	t_timeval			food_t;
	t_timeval			birth;
	int					ready;
	int					x;
	int					y;
	int					o;
	struct s_egg		*next;
}						t_egg;

typedef struct			s_alist
{
	void				(*action)(t_data*, int, char**, t_timeval**);
	char				**cmd;
	t_timeval			*timer;
	struct s_alist		*next;
}						t_alist;

typedef struct			s_player
{
	char				*team;
	int					cs;
	int					x;
	int					y;
	int					o;
	int					level;
	int					food;
	t_timeval			food_t;
	int					linemate;
	int					deraumere;
	int					sibur;
	int					mendiane;
	int					phiras;
	int					thystame;
	char				*msg;
	int					drop;
	int					get;
	t_alist				*actions;
	struct s_spell		*spell;
}						t_player;

typedef struct			s_fov
{
	int					cs;
	int					x;
	int					y;
	int					o;
	int					seen;
	int					last;
	int					level;
	int					len;
	t_player			*player;
}						t_fov;

typedef struct			s_plist
{
	t_player			*player;
	struct s_plist		*next;
}						t_plist;

typedef struct			s_fd
{
	int					type;
	void				(*fct_read)(t_data*, int);
	void				(*fct_write)(t_data*, int);
	char				buf_read[BUF_SIZE + 1];
	char				buf_write[BUF_SIZE + 1];
	t_player			player;
}						t_fd;

typedef struct			s_gcmd
{
	char				*cmd;
	void				(*fct)(t_data*, int, char**);
}						t_gcmd;

typedef struct			s_cmd
{
	char				*cmd;
	void				(*fct)(t_data*, int, char**, t_timeval**);
}						t_cmd;

typedef struct			s_tlist
{
	char				*name;
	int					slots;
	t_plist				*list;
	struct s_tlist		*next;
}						t_tlist;

typedef struct			s_square
{
	int					x;
	int					y;
	int					food;
	int					linemate;
	int					deraumere;
	int					sibur;
	int					mendiane;
	int					phiras;
	int					thystame;
}						t_square;

typedef struct			s_spell
{
	int					x;
	int					y;
	int					level;
	t_player			*owner;
	t_plist				*plist;
	t_timeval			timer;
	int					success;
	struct s_spell		*next;
}						t_spell;

struct					s_data
{
	int					run;
	char				*name;
	int					port;
	int					x;
	int					y;
	t_tlist				*teams;
	t_egg				*eggs;
	int					egg_nb;
	t_spell				*spells;
	int					**spell_tab;
	int					max_clients;
	int					time;
	t_square			**map;
	int					fd_nb;
	int					max_fd;
	t_fd				*fds;
	int					sel;
	fd_set				fd_read;
	fd_set				fd_write;
	struct timeval		timeout;
	t_cmd				cmds[CMD_NB];
	t_gcmd				gcmds[GCMD_NB];
};

int						direction(int dir, t_player *target);
void					disperse(t_data *data, t_spell *spell);
void					disperse_linemate(t_data *data, t_spell *spell);
void					disperse_deraumere(t_data *data, t_spell *spell);
void					disperse_sibur(t_data *data, t_spell *spell);
void					check_opt(t_data *data);
void					init_spell_tab(t_data *data);
void					action_add(t_data *data, t_alist **actions,
									t_cmd action, char **cmd);
void					action_delfirst(t_alist **alist);
void					check_fd(t_data *data);
void					clean_eggs(t_data *data);
void					clean_fd(t_fd *fd);
void					clean_map(t_data *data);
void					clean_players(t_plist **plist);
void					clean_spell_tab(t_data *data);
void					clean_spells(t_data *data);
void					clean_teams(t_data *data);
void					client_read(t_data *data, int cs);
void					client_write(t_data *data, int cs);
void					ccmd_bcast(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_drop(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_fork(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_forward(t_data *data, int cs, char **cmd,
										t_timeval **t);
void					ccmd_incant(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_invent(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_left(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_look(t_data *data, int cs, char **cmd,
									t_timeval **t);
t_square				*see(t_data *data, t_fov *fov);
char					*concatenate(t_data *data, int cs, t_square *square);
void					ccmd_max(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_push(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_right(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					ccmd_take(t_data *data, int cs, char **cmd,
									t_timeval **t);
void					cmd_handl(t_data *data, char *cmd, int cs);
void					create_cmds(t_data *data);
void					create_gcmds(t_data *data);
void					egg_del(t_egg **list, t_egg *egg);
void					error(char *str);
void					free_split(char **tab);
char					*ft_itoa(int n);
void					gcmd_bct(t_data *data, int cs, char **cmd);
void					gcmd_mct(t_data *data, int cs, char **cmd);
void					gcmd_msz(t_data *data, int cs, char **cmd);
void					gcmd_pin(t_data *data, int cs, char **cmd);
void					gcmd_plv(t_data *data, int cs, char **cmd);
void					gcmd_ppo(t_data *data, int cs, char **cmd);
void					gcmd_sgt(t_data *data, int cs, char **cmd);
void					gcmd_sst(t_data *data, int cs, char **cmd);
void					gcmd_tna(t_data *data, int cs, char **cmd);
void					get_height(char *arg, t_data *data);
void					get_maxclients(char *arg, t_data *data);
t_player				*get_player(t_data *data, int cs);
void					get_port(char *arg, t_data *data);
t_square				*get_square(t_data *data, int x, int y);
void					get_teams(char **argv, int *i, t_data *data);
void					get_time(char *arg, t_data *data);
void					get_width(char *arg, t_data *data);
void					gui_bct(void *param, int cs);
void					gui_broadcast(t_data *data, void (*gui_msg)(void*, int),
										void *arg);
void					gui_ebo(void *param, int cs);
void					gui_edi(void *param, int cs);
void					gui_eht(void *param, int cs);
void					gui_elist(t_data *data, int cs);
void					gui_enw(void *param, int cs);
void					gui_init(t_data *data, int cs);
void					gui_mct(t_data *data, int cs);
void					gui_msz(t_data *data, int cs);
void					gui_pbc(void *param, int cs);
void					gui_pdi(void *param, int cs);
void					gui_pdr(void *param, int cs);
void					gui_pex(void *param, int cs);
void					gui_pfk(void *param, int cs);
void					gui_pgt(void *param, int cs);
void					gui_pic(void *param, int cs);
void					gui_pie(void *param, int cs);
void					gui_plist(t_data *data, int cs);
void					gui_pin(void *param, int cs);
void					gui_pnw(void *param, int cs);
void					gui_plv(void *param, int cs);
void					gui_ppo(void *param, int cs);
void					gui_sbp(void *null, int cs);
void					gui_seg(void *param, int cs);
void					gui_sgt(void *param, int cs);
void					gui_msg(char *msg, int cs);
void					gui_suc(void *null, int cs);
void					gui_tna(t_data *data, int cs);
void					init_data(t_data *data, char **av);
void					init_fd(t_data *data);
void					init_server(t_data *data);
int						mod(int nb, int mod);
void					player_add(t_plist **plist, t_player *player);
void					player_death(t_data *data, t_player *player);
void					player_del(t_plist **list, t_player *player);
void					player_init(t_data *data, t_tlist *team, int cs);
void					quit_game(t_data *data);
void					routine_action(t_data *data);
void					routine_egg(t_data *data);
void					routine_food(t_data *data);
void					routine_spell(t_data *data);
void					spell_del(t_spell **list, t_spell *spell);
char					*split_join(char **split);
char					**split_dup(char **split);
int						spell_check(t_data *data, t_player *player, int status);
void					srv_accept(t_data *data, int sock);
char					**strsplit(char const *s, char c);
char					*strsub(char const *s, unsigned int start, size_t len);
void					team_add(t_data *data, char *name);
void					team_del(t_tlist **list, t_tlist *team);
void					team_join(t_data *data, char *cmd, int cs);
t_timeval				time_add(t_data *data, t_timeval *time, int coef);
int						time_diff(t_timeval *t1, t_timeval *t2);
void					usage(char *str);
void					win_check(t_data *data);
#endif
