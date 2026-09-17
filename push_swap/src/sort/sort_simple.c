/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_non_lis(t_ctx *ctx, int to_push)
{
	while (to_push > 0)
	{
		if (ctx->a->keep)
			ra(ctx);
		else
		{
			pb(ctx);
			to_push--;
		}
	}
}

static void	rotate_a_by(t_ctx *ctx, int count)
{
	while (count > 0)
	{
		ra(ctx);
		count--;
	}
	while (count < 0)
	{
		rra(ctx);
		count++;
	}
}

static void	rotate_b_by(t_ctx *ctx, int count)
{
	while (count > 0)
	{
		rb(ctx);
		count--;
	}
	while (count < 0)
	{
		rrb(ctx);
		count++;
	}
}

static void	insert_cheapest(t_ctx *ctx)
{
	t_move	move;

	move = cheapest_move(ctx);
	while (move.a > 0 && move.b > 0)
	{
		rr(ctx);
		move.a--;
		move.b--;
	}
	while (move.a < 0 && move.b < 0)
	{
		rrr(ctx);
		move.a++;
		move.b++;
	}
	rotate_a_by(ctx, move.a);
	rotate_b_by(ctx, move.b);
	pa(ctx);
}

void	sort_simple(t_ctx *ctx)
{
	int	size;
	int	kept;

	size = stack_size(ctx->a);
	if (size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	assign_indexes(ctx->a);
	kept = mark_lis(ctx->a, size);
	if (kept < 0)
	{
		sort_small(ctx);
		return ;
	}
	push_non_lis(ctx, size - kept);
	while (ctx->b)
		insert_cheapest(ctx);
	rotate_min_to_top(ctx);
}
