/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:59:18 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/26 23:15:09 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				node_t;

int	main(void)
{
	char str[] = "Warasw 42 gedion";
	char buffer[] = "Hello";
	char buf2[] = "Hello";
	char csrc[] = "Gedion Bekur";
	char cdest[20];
	char str2[] = "Hhello";
	char str3[] = "Hhello";
	char src[20] = "ABCDEFGHIJ";
	char dest[20];

	// ft_isalpha
	printf("ft_isalpha: %d\n", ft_isalpha(1));
	printf("isalpha: %d\n", isalpha(1));
	// ft_isdigit
	printf("ft_isdigit: %d\n", ft_isdigit('5'));
	printf("isdigit: %d\n", ft_isdigit('5'));
	// isalnum
	printf("ft_isalnum: %d\n", ft_isalnum(')'));
	printf("isalnum: %d\n", isalnum(')'));
	printf("ft_isascii: %d\n", ft_isascii(127));
	printf("isascii: %d\n", isascii(127));
	printf("ft_isprint: %d\n", ft_isprint(128));
	printf("isprint: %d\n", isprint(31));
	printf("ft_strlen: %lu\n", (long)ft_strlen(str));
	printf("strlen: %lu\n", (long)strlen(str));
	printf("ft_memset: %s\n", (char *)ft_memset(buffer, 'Z', 3));
	printf("memset: %s\n", (char *)memset(buffer, 48, 3));
	printf("before ft_bzero : %s\n", buf2);
	ft_bzero(buf2, 5);
	printf("after bzero : %s\n", buf2);
	bzero(buf2, 5);
	printf("after bzero : %s\n", buf2);
	ft_memcpy(cdest, csrc, strlen(csrc) + 1);
	printf("Copied string is %s\n", cdest);
	memcpy(cdest, csrc, strlen(csrc) + 1);
	printf("Orginal is %s\n", cdest);
	printf("%s\n", (char *)ft_memmove(str2 + 1, str2, 3));
	printf("%s\n", (char *)memmove(str3 + 1, str3, 3));
	ft_strlcpy(dest, src, 3);
	strlcpy(dest, src, 3);
	printf("ft_strlcpy: %s\n", dest);
	return (0);
}