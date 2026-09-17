/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_value(t_stack **a, int value)
{
	t_stack	*new;

	if (has_duplicate(*a, value))
		return (0);
	new = stack_new(value);
	if (!new)
		return (0);
	stack_add_back(a, new);
	return (1);
}

static int	parse_string(t_stack **a, char *arg, int argc, int *count)
{
	int	value;

	if (!*arg || (argc > 1 && has_space(arg)))
		return (0);
	while (is_space(*arg))
		arg++;
	while (*arg)
	{
		if (!read_number(&arg, &value) || !add_value(a, value))
			return (0);
		(*count)++;
		while (is_space(*arg))
			arg++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack **a)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < argc)
	{
		if (!parse_string(a, argv[index], argc, &count))
		{
			stack_clear(a);
			return (0);
		}
		index++;
	}
	return (count > 0);
}
