/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:48:34 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/27 22:51:43 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <helpers.h>
#include <libft.h>
#include <macro.h>
#include <proto.h>
#include <signal.h>
#include <stdlib.h>
#include <termcap.h>

static void	init_env(char **envp)
{
	data()->envp = (char ***)malloc(sizeof(char **));
	data()->envp[0] = envp;
}

void		init(char **envp)
{
	struct sigaction	sig;

	tgetent(data()->buffer, getenv("TERM"));
	init_env(dup_env(envp));
	tinit(data());
	ft_memset((void *)&sig, '\0', sizeof(sig));
	sig.sa_handler = &sighandler;
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGTSTP, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
	sigaction(SIGHUP, &sig, NULL);
}
