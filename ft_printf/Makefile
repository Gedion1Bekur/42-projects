# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 20:25:57 by szerisen          #+#    #+#              #
#    Updated: 2026/07/31 17:39:29 by gbekur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
RM		= rm -f
GCCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS =	ft_printf.c\

.c.o:
		${GCCF} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${LIB} ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		

re:		fclean all
