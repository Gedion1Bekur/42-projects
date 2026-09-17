/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/15 00:00:00 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	has_space(char *str)
{
	while (*str)
	{
		if (is_space(*str))
			return (1);
		str++;
	}
	return (0);
}

int	read_number(char **str, int *value)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && (-num) < INT_MIN))
			return (0);
		(*str)++;
	}
	if (**str && !is_space(**str))
		return (0);
	*value = (int)(num * sign);
	return (1);
}

int	parsing_int(char *str, int *value)
{
	return (read_number(&str, value) && !*str);
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
