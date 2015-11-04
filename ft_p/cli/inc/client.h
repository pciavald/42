/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 19:00:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 22:20:03 by pciavald         ###   ########.fr       */
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

# define CMD_N		7
# define BUF_SIZE	1024

typedef struct protoent			*t_protoent;
typedef struct sockaddr_in		t_sin;

int		create_client(char *addr, int port);
void	usage(char *pname);
void	quit(int sock);
char	**init_cmd_tab(void);

#endif
