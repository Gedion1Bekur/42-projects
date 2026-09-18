/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ra(t_ctx *ctx)
{
	if (rotate(&ctx->a))
		write_op(ctx, "ra\n", OP_RA);
}

void	rb(t_ctx *ctx)
{
	if (rotate(&ctx->b))
		write_op(ctx, "rb\n", OP_RB);
}

void	rr(t_ctx *ctx)
{
	int	a_changed;
	int	b_changed;

	a_changed = rotate(&ctx->a);
	b_changed = rotate(&ctx->b);
	if (a_changed || b_changed)
		write_op(ctx, "rr\n", OP_RR);
}
