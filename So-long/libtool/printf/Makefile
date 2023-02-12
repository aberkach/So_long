# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 01:04:55 by abberkac          #+#    #+#              #
#    Updated: 2022/11/28 09:55:59 by abberkac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	ft_printf.c\
		ft_putstr.c\
		ft_putnbr_i_d.c\
		ft_putchar.c\
		ft_puthex.c\
		ft_putunbr.c\
		ft_putptr.c
 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re