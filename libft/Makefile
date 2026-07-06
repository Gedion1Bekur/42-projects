NAME = libft.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
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
	  ft_strlcpy \
	  ft_strlcat \
	  ft_tolower \
	  ft_toupper \
	  ft_strchr \
	  ft_strrchr \
	  ft_strncmp \
	  ft_memchr \
	  ft_memcmp \
	  ft_atoi \
	  ft_strnstr \
	  ft_strdup \
	  ft_substr
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all : $(NAME)	

$(NAME) : $(OBJS)
	@$(AR) $@ $^	
	@echo "compiled :) $(NAME)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "obj cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "cleaned all :)"

re: fclean all

.PHONY: all clean fclean re