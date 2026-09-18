# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/17 21:24:43 by hcherif           #+#    #+#              #
#    Updated: 2026/09/17 21:25:33 by hcherif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = include/push_swap.h

SRC = src/main \
	src/stack/stack_utils src/stack/operations \
	src/stack/operations_push src/stack/operations_rotate \
	src/stack/operations_reverse_rotate \
	src/parse/parse_args src/parse/parse_utils src/parse/parse_mode \
	src/sort/sort src/sort/sort_utils src/sort/disorder \
	src/sort/sort_small src/sort/sort_simple src/sort/sort_lis \
	src/sort/sort_move src/sort/sort_medium src/sort/sort_complex \
	src/bench/bench src/bench/bench_utils

OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
