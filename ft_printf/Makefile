# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 20:25:57 by szerisen          #+#    #+#              #
#    Updated: 2026/08/01 22:23:20 by gbekur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

SRCS    = ft_printf.c \
          ft_putchar.c \
          ft_putstr.c \
          ft_putnbr.c \
          ft_putunsigned.c \
          ft_puthex.c \
          ft_putptr.c

OBJS    = ${SRCS:.c=.o}
RM      = rm -f
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LIB     = ar rcs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${LIB} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
		
re:		fclean all

.PHONY: all clean fclean re

