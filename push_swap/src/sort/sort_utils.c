/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				index++;
			other = other->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	position_of_min(t_stack *stack)
{
	int	position;
	int	min;
	int	index;

	position = 0;
	index = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			position = index;
		}
		index++;
		stack = stack->next;
	}
	return (position);
}

int	position_of_max(t_stack *stack)
{
	int	position;
	int	max;
	int	index;

	position = 0;
	index = 0;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			position = index;
		}
		index++;
		stack = stack->next;
	}
	return (position);
}

int	target_position(t_stack *a, int index)
{
	int		position;
	int		target;
	int		target_index;
	t_stack	*node;

	target = -1;
	target_index = INT_MAX;
	position = 0;
	node = a;
	while (node)
	{
		if (node->index > index && node->index < target_index)
		{
			target_index = node->index;
			target = position;
		}
		position++;
		node = node->next;
	}
	if (target == -1)
		return (position_of_min(a));
	return (target);
}

void	sort_three(t_ctx *ctx)
{
	t_stack	*a;

	a = ctx->a;
	if (a->value > a->next->value && a->value > a->next->next->value)
		ra(ctx);
	else if (a->next->value > a->value
		&& a->next->value > a->next->next->value)
		rra(ctx);
	if (ctx->a->value > ctx->a->next->value)
		sa(ctx);
}
