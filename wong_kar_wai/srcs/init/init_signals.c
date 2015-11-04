/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 02:12:29 by tcharlat          #+#    #+#             */
/*   Updated: 2015/01/31 02:12:31 by tcharlat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_fgsig(int signum)
{
	(void)signum;
	refresh();
	getch();
}

void		init_signals(void)
{
	signal(SIGCONT, ft_fgsig);
}
