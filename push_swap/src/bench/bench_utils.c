/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	put_str_fd(char *s, int fd)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	write(fd, s, length);
}

void	put_nbr_fd(long n, int fd)
{
	char	digit;

	if (n < 0)
	{
		put_str_fd("-", fd);
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}

void	put_percent_fd(double ratio, int fd)
{
	long	hundredths;

	hundredths = (long)(ratio * 10000.0 + 0.5);
	put_nbr_fd(hundredths / 100, fd);
	put_str_fd(".", fd);
	if (hundredths % 100 < 10)
		put_str_fd("0", fd);
	put_nbr_fd(hundredths % 100, fd);
	put_str_fd("%", fd);
}

char	*strategy_name(t_ctx *ctx)
{
	if (ctx->mode == MODE_SIMPLE)
		return ("Simple");
	if (ctx->mode == MODE_MEDIUM)
		return ("Medium");
	if (ctx->mode == MODE_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*complexity_class(t_ctx *ctx)
{
	t_sort_mode	effective;

	effective = ctx->mode;
	if (effective == MODE_ADAPTIVE)
	{
		if (ctx->disorder < 0.2)
			effective = MODE_SIMPLE;
		else if (ctx->disorder < 0.5)
			effective = MODE_MEDIUM;
		else
			effective = MODE_COMPLEX;
	}
	if (effective == MODE_SIMPLE)
		return ("O(n^2)");
	if (effective == MODE_MEDIUM)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}
