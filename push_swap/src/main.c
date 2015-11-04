/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:29:42 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/18 23:33:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(char *str, int args)
{
	(void)args;
	ft_putstr(str);
}

void	yo(t_num *tmp)
{
	while (tmp)
	{
		ft_putnbr(tmp->n);
		ft_putstr(" ");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

int		done(t_num *list)
{
	while (list)
	{
		if (list->next && list->next->n < list->n)
			return (0);
		list = list->next;
	}
	return (1);
}

int		sort(t_num **l_a, t_num **l_b, int args)
{
	t_num	*la;
	t_num	*lb;
	int		ret;

	la = *l_a;
	lb = *l_b;
	ret = 0;
	while (!done(la) || lb)
	{
		while (!done(la))
		{
			if (la->n > la->next->n)
			{
				sa(&la, &lb, args);
				ret = 1;
			}
			else
				pb(&la, &lb, args);
		}
		if (lb)
			pa(&la, &lb, args);
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_num		*l_a;
	t_num		*l_b;
	int			args;

	args = 0;
	l_b = NULL;
	l_a = make_list(&(argv[1]), argc - 1);
	if (sort(&l_a, &l_b, args))
		ft_putstr("\n");
	return (0);
}
