/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:01:54 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

int	parse_mode(char *arg, t_sort_mode *mode)
{
	if (str_equal(arg, "--simple"))
		*mode = MODE_SIMPLE;
	else if (str_equal(arg, "--medium"))
		*mode = MODE_MEDIUM;
	else if (str_equal(arg, "--complex"))
		*mode = MODE_COMPLEX;
	else if (str_equal(arg, "--adaptive"))
		*mode = MODE_ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_ctx *ctx)
{
	int	index;

	index = 1;
	while (index < argc && argv[index][0] == '-' && argv[index][1] == '-')
	{
		if (str_equal(argv[index], "--bench"))
			ctx->bench = 1;
		else if (!parse_mode(argv[index], &ctx->mode))
			return (-1);
		index++;
	}
	return (index);
}
