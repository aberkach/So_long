/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:50:42 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/27 21:23:23 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, char c)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (nb < 16)
		len += ft_putchar(str[nb]);
	else
	{
		len += ft_puthex(nb / 16, c);
		len += ft_puthex(nb % 16, c);
	}
	return (len);
}
