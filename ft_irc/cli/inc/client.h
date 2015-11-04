/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 19:00:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 22:09:46 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>

# define BUF_SIZE				4096
# define PROMPT					"\e[34m###\e[0m "

typedef struct protoent			*t_protoent;
typedef struct hostent			*t_hostent;
typedef struct sockaddr_in		t_sin;

typedef struct					s_fd
{
	char						buf_read[BUF_SIZE + 1];
	char						buf_write[BUF_SIZE + 1];
}								t_fd;

typedef struct					s_env
{
	int							s;
	t_fd						*fds;
	int							r;
	int							i;
	fd_set						fd_read;
	fd_set						fd_write;
	char						*nick;
	char						*chan;
}								t_env;

void							client_write(t_env *e, int s);
void							client_read(t_env *e, int s);
void							init_fds(t_env *e, int sock);
int								create_client(char *addr, int port);
void							usage(char *pname);
void							quit(int sock);
void							init_cmd_tab(t_env *e);
char							*nick(int cs);
void							init_fd(t_env *e);
void							do_select(t_env *e);
void							check_fd(t_env *e);

#endif
