/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:47 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/28 09:59:25 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_checking(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'x' || c == 'p')
		return (1);
	else if (c == 'X' || c == 'u' || c == 'c' || c == '%')
		return (1);
	return (0);
}

static int	put_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr_i_d(va_arg(args, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format_checking(format[i]))
				len += put_format(args, format[i]);
			else
				len += ft_putchar(format[i]);
			i++;
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(args);
	return (len);
}
