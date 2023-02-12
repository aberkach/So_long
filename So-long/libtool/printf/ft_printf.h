/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:46 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/28 09:48:45 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr_i_d(int nb);
int	ft_putunbr(unsigned int nbr);
int	ft_putchar(int c);
int	ft_puthex(unsigned long nb, char c);
int	ft_putptr(unsigned long nbr);

#endif