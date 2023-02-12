/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:25:26 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/28 09:52:28 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	unsigned int	n;

	n = 0;
	if (nbr <= 9)
		n += ft_putchar(nbr + 48);
	else
	{
		n += ft_putunbr(nbr / 10);
		n += ft_putchar((nbr % 10) + 48);
	}
	return (n);
}
