/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:14:03 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/28 09:50:14 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght(long nbr)
{
	int	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	ft_putnbr_i_d(int nb)
{
	int		i;
	long	nbr;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		i = 1;
	}
	ft_putnbr(nbr);
	i += lenght(nbr);
	return (i);
}

// int	ft_putnbr(long nb)
// {
// 	long	count;

// 	count = 0;
// 	if (nb == -2147483648)
// 	{
// 		count += ft_putchar('-');
// 		count += ft_putchar('2');
// 		count += ft_putnbr(147483648);
// 	}
// 	if (nb < 0)
// 	{
// 		nb = -nb;
// 		count += ft_putchar('-');
// 	}
// 	if (nb >= 10)
// 	{
// 		count += ft_putnbr(nb / 10);
// 		count += ft_putnbr(nb % 10);
// 	}
// 	else
// 		count += ft_putchar(nb + 48);
// 	return (count);
// }
