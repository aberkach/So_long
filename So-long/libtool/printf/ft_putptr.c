/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:12:31 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/28 10:11:59 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nbr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(nbr, 'x');
	return (len);
}
