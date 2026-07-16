*This project has been created as part of the 42 curriculum by gbekur.*

# 42 Projects Repository

## Description
This repository contains a collection of C programming exercises completed as part of the 42 curriculum. The main focus is on building a solid understanding of memory management, string handling, linked lists, and low-level programming concepts.

The core project in this repository is a custom C library named libft. It recreates a subset of the standard C library functions and adds linked-list utilities that are useful for future 42 projects such as ft_printf, get_next_line, and more advanced implementations.

## Detailed Description of the Library
The custom library created for this project is called libft and is implemented in the libft directory.

It provides:
- Character classification helpers such as ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, and ft_isprint.
- String and memory manipulation functions such as ft_strlen, ft_memset, ft_memcpy, ft_memmove, ft_strlcpy, and ft_strlcat.
- String comparison and search utilities such as ft_strchr, ft_strrchr, ft_strncmp, ft_memcmp, ft_strnstr, and ft_atoi.
- Dynamic memory and string allocation helpers such as ft_calloc, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, and ft_striteri.
- File descriptor output functions such as ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, and ft_putnbr_fd.
- Linked-list tools for creation, insertion, traversal, deletion, and mapping.

This library is designed to be reusable and portable, making it a foundation for later projects that require robust string and memory handling.

## Instructions
### Build the library
From the repository root, compile the library with:

```sh
cd libft
make
```

This will generate the static library file libft.a.

### Clean generated files
```sh
make clean
make fclean
```

### Use the library in another program
You can link your own C program against the library using:

```sh
gcc your_program.c -Llibft -lft -Ilibft
```

If you want to test the library interactively, you can also use the sample file in the libft directory as a reference.

## Project Structure
- libft/: implementation of the custom library and its Makefile.
- ft_printf/: exercises and work related to formatted output.
- get_next_line/: implementation of a function to read a line from a file descriptor.
- README.md: project overview and usage information.

## Resources
Classic references and material related to this topic include:
- The C standard library documentation and man pages.
- The 42 Libft subject and its associated learning resources.
- General C programming tutorials focused on pointers, memory allocation, and strings.

AI usage:
- I used AI assistance to help structure this README and clarify the project overview.
