/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next->next = *stack;
	*stack = before_last->next;
	before_last->next = NULL;
	return (1);
}

void	rra(t_ctx *ctx)
{
	if (reverse_rotate(&ctx->a))
		write_op(ctx, "rra\n", OP_RRA);
}

void	rrb(t_ctx *ctx)
{
	if (reverse_rotate(&ctx->b))
		write_op(ctx, "rrb\n", OP_RRB);
}

void	rrr(t_ctx *ctx)
{
	int	a_changed;
	int	b_changed;

	a_changed = reverse_rotate(&ctx->a);
	b_changed = reverse_rotate(&ctx->b);
	if (a_changed || b_changed)
		write_op(ctx, "rrr\n", OP_RRR);
}
