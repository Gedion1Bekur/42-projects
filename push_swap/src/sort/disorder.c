/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_inversions(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other;
	long	mistakes;

	mistakes = 0;
	current = stack;
	while (current)
	{
		other = current->next;
		while (other)
		{
			if (current->value > other->value)
				mistakes++;
			other = other->next;
		}
		current = current->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *stack)
{
	long	size;
	long	total_pairs;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	total_pairs = size * (size - 1) / 2;
	return ((double)count_inversions(stack) / (double)total_pairs);
}
