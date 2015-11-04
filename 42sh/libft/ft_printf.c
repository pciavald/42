/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 21:37:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/03/27 20:45:15 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

static int	print_arg(char c, va_list *ap)
{
	if (!c)
		return (0);
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char*)));
	else
		write(1, &c, 1);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		seg_start;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		seg_start = i;
		while (format[i] && format[i] != '%')
			i++;
		if ((i - seg_start) > 0)
		{
			len += i - seg_start;
			write(1, format + seg_start, i - seg_start);
		}
		if (format[i] == '%')
			len += print_arg(format[++i], &ap);
		if (format[i])
			i++;
	}
	va_end(ap);
	return (len);
}
