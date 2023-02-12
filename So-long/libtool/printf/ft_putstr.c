/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:16:40 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/27 21:23:52 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		len = write(1, "(null)", 6);
	else
	{
		while (str[len] != '\0')
		{
			ft_putchar(str[len]);
			len++;
		}
	}
	return (len);
}
