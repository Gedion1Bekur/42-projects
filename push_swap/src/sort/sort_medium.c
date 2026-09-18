/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

static void	push_chunks(t_ctx *ctx)
{
	int	chunk;
	int	pushed;

	chunk = chunk_size(stack_size(ctx->a));
	pushed = 0;
	while (ctx->a)
	{
		if (ctx->a->index < pushed + chunk)
		{
			pb(ctx);
			pushed++;
			if (ctx->b->next && ctx->b->index < ctx->b->next->index)
				rb(ctx);
		}
		else
			ra(ctx);
	}
}

static void	pop_back(t_ctx *ctx)
{
	int	position;
	int	size;

	while (ctx->b)
	{
		position = position_of_max(ctx->b);
		size = stack_size(ctx->b);
		if (position <= size / 2)
			while (position-- > 0)
				rb(ctx);
		else
			while (position++ < size)
				rrb(ctx);
		pa(ctx);
	}
}

void	sort_medium(t_ctx *ctx)
{
	assign_indexes(ctx->a);
	push_chunks(ctx);
	pop_back(ctx);
}
