/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:42:11 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/19 00:56:38 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int a)
{
	int	count;

	count = 0;
	if (a < 0)
		count++;
	while (a)
	{
		count++;
		a = a / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	a;
	int		len;
	char	*nbr;

	a = n;
	if (a == 0)
		return (ft_strdup("0"));
	len = n_len(a);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		a *= -1;
	}
	nbr[len--] = '\0';
	while (a != 0)
	{
		nbr[len] = (a % 10) + '0' ;
		a = a / 10;
		len--;
	}
	return (nbr);
}
