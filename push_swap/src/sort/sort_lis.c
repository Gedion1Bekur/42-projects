/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_lengths(int *arr, int *len, int *prev, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	longest_end(int *len, int size)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < size)
	{
		if (len[i] > len[best])
			best = i;
		i++;
	}
	return (best);
}

static void	apply_keep_flags(t_stack *stack, int *prev, int *flag, int end)
{
	int	i;

	while (end >= 0)
	{
		flag[end] = 1;
		end = prev[end];
	}
	i = 0;
	while (stack)
	{
		stack->keep = flag[i];
		stack = stack->next;
		i++;
	}
}

int	mark_lis(t_stack *stack, int size)
{
	int		*block;
	int		i;
	int		end;
	int		kept;
	t_stack	*node;

	block = malloc(sizeof(int) * size * 4);
	if (!block)
		return (-1);
	i = 0;
	node = stack;
	while (node)
	{
		block[i] = node->index;
		block[3 * size + i] = 0;
		node = node->next;
		i++;
	}
	fill_lengths(block, block + size, block + 2 * size, size);
	end = longest_end(block + size, size);
	kept = block[size + end];
	apply_keep_flags(stack, block + 2 * size, block + 3 * size, end);
	free(block);
	return (kept);
}
