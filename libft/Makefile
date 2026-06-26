NAME = libft.a
CC = gcc
AR = ar rcs
CfLAGS = -Wall -Wextra -Werror
MAIN = main.c
SRC = ft_isalpha \
      ft_isdigit \
      ft_isalnum \
      ft_isascii \
      ft_isprint \
      ft_strlen \
      ft_memset \
      ft_bzero \
	  ft_memcpy \
	  ft_memmove \
	  ft_strlcpy
SRCS = $(addsuffix .c ,$(SRC))
OBJS = $(addsuffix .o ,$(SRC))

all : $(NAME)	

$(NAME) : $(OBJS)
	@$(AR) $@ $^	
	@echo "complied :) $(NAME)"
%.o : %.c
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "obj cleaned"
fclean: clean
	@rm -fr $(NAME)
	@echo "cleaned all :)"
re: fclean all

.PHONY: all clean fclean re
#.SILENT:
