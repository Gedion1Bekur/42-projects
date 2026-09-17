/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	make_move(int a, int b)
{
	t_move	move;

	move.a = a;
	move.b = b;
	return (move);
}

static int	move_cost(t_move move)
{
	int	a;
	int	b;

	a = move.a;
	b = move.b;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if ((move.a < 0) != (move.b < 0))
		return (a + b);
	if (a > b)
		return (a);
	return (b);
}

static t_move	best_move(int pos_a, int pos_b, int *sizes)
{
	t_move	best;
	t_move	option;

	best = make_move(pos_a, pos_b);
	option = make_move(pos_a - sizes[0], pos_b - sizes[1]);
	if (move_cost(option) < move_cost(best))
		best = option;
	option = make_move(pos_a, pos_b - sizes[1]);
	if (move_cost(option) < move_cost(best))
		best = option;
	option = make_move(pos_a - sizes[0], pos_b);
	if (move_cost(option) < move_cost(best))
		best = option;
	return (best);
}

static void	keep_cheaper(t_move *best, int pos_a, int pos_b, int *sizes)
{
	t_move	move;

	move = best_move(pos_a, pos_b, sizes);
	if (move_cost(move) < move_cost(*best))
		*best = move;
}

t_move	cheapest_move(t_ctx *ctx)
{
	t_stack	*node;
	t_move	best;
	int		pos_b;
	int		rot_b;
	int		sizes[2];

	sizes[0] = stack_size(ctx->a);
	sizes[1] = stack_size(ctx->b);
	node = ctx->b;
	best = best_move(target_position(ctx->a, node->index), 0, sizes);
	pos_b = 0;
	while (node)
	{
		rot_b = pos_b;
		if (sizes[1] - pos_b < rot_b)
			rot_b = sizes[1] - pos_b;
		if (rot_b < move_cost(best))
			keep_cheaper(&best, target_position(ctx->a, node->index),
				pos_b, sizes);
		pos_b++;
		node = node->next;
	}
	return (best);
}
