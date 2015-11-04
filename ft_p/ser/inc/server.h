/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 19:00:02 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:38:49 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <fcntl.h>

# define BUF_LEN		1024
# define RED			"\x1B[0;31m"
# define GREEN			"\x1B[0;32m"
# define NC				"\x1B[0m"

# define FN_N			5
# define GET_N			0
# define PUT_N			1
# define CD_N			2
# define QUIT_N			3
# define HELP_N			4

# define ERROR			0
# define SUCCESS		1

typedef struct protoent			*t_protoent;
typedef struct sockaddr_in		t_sin;
typedef struct stat				t_stat;

int		get(char **split, int sock);
int		put(char **split, int sock);
int		cd(char **split, int sock);
int		quit(char **split, int sock);
int		help(char **split, int sock);
char	**init_nm_tab(void);

void	usage(char *pname);
void	sighandler(int signum);
int		get_sock(char *leport);

void	print_c(char *str, char *c);
void	run(int sock);
int		create_server(int port);

char	*executable(char **str);

void	client_status(int stat, int cs);
void	client_connect(int id);
void	client_quit(int id);

#endif
