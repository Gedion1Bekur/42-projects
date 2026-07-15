/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:59:18 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:33:15 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
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
	char src[] = "ABCDEFGHIJ";
	char dest[5];

	char var_ll = 'C';
	char var_hl = 'c';

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

	printf("from this line below all mem funcs \n");
	printf("*********************************\n");
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
	printf("ft_memmove: %s\n", (char *)ft_memmove(str2 + 2, str2, 3));
	printf("mememove: %s\n ", (char *)memmove(str3 + 2, str3, 3));
	// ft_strlcpy(dest, src, sizeof(dest));

	printf("from this line below all strstr funcs \n");
	printf("*********************************\n");

	strlcpy(dest, src, sizeof(dest));

	printf("ft_strlcpy: %s\n", dest);
	int result1 = ft_strlcpy(dest, src, sizeof(dest));
	printf("ft_strlcpy return (value): %d\n", result1);

	// --- CASE 1: Buffer has plenty of room ---
	char b_ft[15] = "Hello ", b_og[15] = "Hello ";
	size_t r_ft = ft_strlcat(b_ft, "World", 15);
	size_t r_og = strlcat(b_og, "World", 15);
	printf("[ft] %s (ret: %zu)\n", b_ft, r_ft);
	printf("[og] %s (ret: %zu)\n", b_og, r_og);
	printf("from this line below all toupper funcs \n");
	printf("*********************************\n");

	printf("or -ll : %d\n", ft_tolower(var_ll));
	printf("To lower: %d\n", tolower(var_ll));
	printf("To Upper: %d\n", ft_toupper(var_hl));
	printf("or-hh : %d\n", toupper(var_hl));

	printf("from this line below all strchr funcs \n");
	printf("*********************************\n");
	char strvar[] = "helloz";
	char find_char = ' ';

	printf("strchr check : %s\n", ft_strchr(strvar, find_char));
	printf("strchr check : %s\n", strchr(strvar, find_char));

	printf("strrchr check : %s\n", ft_strrchr(strvar, find_char));
	printf("strrchr check : %s\n", strrchr(strvar, find_char));

	/*
	The Zero Case: What happens if n = 0?The Overflow Case: What happens if n = 1000 but the string only has 3 letters?The Empty Case: What happens if one string is totally empty ("")?If you test your change against those three scenarios using real numbers,
	you will see the logic bugs immediately before you even compile the code.
		*/

	// memecpr and main memory funtions

	char memcpr1[] = {'a', 'B', 65};
	int fnd = 65;
	printf("ft_memchr check : %s\n", (char *)ft_memchr(memcpr1, fnd, 6));
	printf("memcpr check : %s\n", (char *)memchr(memcpr1, fnd, 6));

	char dst_mine[10] = "ABCz";
	char src_mem[] = "ABCZ";
	int reuslt1 = ft_memcmp(dst_mine, src_mem, 4);
	int reuslt2 = memcmp(dst_mine, src_mem, 4);
	printf("ft_memcmp: %d\n", reuslt1);
	printf("OR memcmp: %d\n", reuslt2);
	;

	printf("Test 1 (orig): %d (Expected: 0)\n", atoi("--42"));

	printf("Test 1 (orig): %d\n", atoi("--42"));
	printf("atoi :edge case Test 1 (your): %d\n", ft_atoi("99999999999999"));
	printf("atoi : edge case Test 1: %d\n", atoi("99999999999999"));

	printf("=== STARTING ATOI TESTS ===\n\n");

	printf("\n");
	// Test 2: Standard negative number with spaces
	printf("Test 2 (orig): %d (Expected: -42)\n", atoi("   -42"));
	printf("Test 2 (your): %d (Expected: -42)\n", ft_atoi("   -42"));

	//  " " Task one final ques haha :)))) ahah finally tho ""
	printf("______________final quest of task on _______ here we go :)\n");
	char big[] = "Gedion 42 student  here we go";
	char lil[] = "no";

	printf("(ft_strnstr/substring) %s\n", ft_strnstr(big, lil, ft_strlen(big)));
	printf("(orig) %s\n", strnstr(big, lil, ft_strlen(big)));

	printf("******************Task 2 *********************\n");
	printf("******************Task 2 *********************\n");

	printf("Result: %s\n", ft_substr("Hello World", 8, 3));
	// char *res = ft_substr("abc", 8, 2);

	// free(res);

	printf("ft_calloc: %p\n", (int *)ft_calloc(8, 3));

	printf("******************Task 2 malloc- calloc- free *********************\n");
	printf("ft_strjoin: %s\n", ft_strjoin("", ""));

	char *res;

	printf("--- Running ft_strtrim Tests ---\n\n");

	// Test 1: Normal trimming from both sides
	res = ft_strtrim("   hello world   ", " ");
	printf("Test 1 (Normal spaces):\nExpected: 'hello world'\nResult:   '%s'\n\n",
		res);
	free(res);

	// Test 2: Multiple different characters in set
	res = ft_strtrim("xXyHello WorldYxx", "xXyY");
	printf("Test 2 (Multiple characters):\nExpected: 'Hello World'\nResult:   '%s'\n\n",
		res);
	free(res);

	// Test 3: Nothing to trim
	res = ft_strtrim("no trim needed", "xyz");
	printf("Test 3 (No matching set):\nExpected: 'no trim needed'\nResult:   '%s'\n\n",
		res);
	free(res);

	// Test 4: String is entirely made of the trim set
	res = ft_strtrim("aaaaaaa", "a");
	printf("Test 4 (Entire string is set):\nExpected: ''\nResult:   '%s'\n\n",
		res);
	free(res);

	// Test 5: Empty string input
	res = ft_strtrim("", "abc");
	printf("Test 5 (Empty string source):\nExpected: ''\nResult:   '%s'\n\n",
		res);
	free(res);

	///

	char *res3;
	char **result;
	int i;

	// 1. Your Strtrim test evaluation
	res3 = ft_strtrim("", "abc");
	printf("Test 5 (Empty string source):\nExpected: ''\nResult:   '%s'\n\n",
		res3);
	free(res3); // FIX: Changed from res to res3

	// 2. Your Split test evaluation (with added print logic)
	printf("Test Split:\nString: \"xxxHelloe the most diffcult onexyz\" | Delimiter: 'x'\n");
	result = ft_split("xxxHelloe the most diffcult onexyz", 'x');
	if (!result)
		return (1);

	i = 0;
	while (result[i] != NULL)
	{
		printf("  [Word %d]: '%s'\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);










	///strAPi 


	

	return (0);
}
