/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:31:45 by pciavald          #+#    #+#             */
/*   Updated: 2014/03/22 04:19:13 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <helpers.h>
#include <libft.h>

void	put_error(char *name, char *str)
{
	if (str)
		ft_printf_fd(2, "42sh: %s: %s: %s\n", name, str, ft_strerror());
	else
		ft_printf_fd(2, "42sh: %s: %s\n", name, ft_strerror());
}

char	*ft_strerror(void)
{
	if (errno == 13)
		return ("Permission denied");
	else if (errno == 2)
		return ("No such file or directory");
	else if (errno == 122)
		return ("Quota exceeded");
	else if (errno == 14)
		return ("Bad address");
	else if (errno == 4)
		return ("Interrupted system call");
	else if (errno == 21)
		return ("Is a directory");
	else if (errno == 5)
		return ("I/O error");
	else if (errno == 40)
		return ("Too may symbolic links encountered");
	else if (errno == 36)
		return ("Filename too long");
	else if (errno == 28)
		return ("No space left on device");
	else
		return ("Unknown error");
}
