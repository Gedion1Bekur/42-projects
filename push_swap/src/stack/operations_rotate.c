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

static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_ctx *ctx)
{
	rotate(&ctx->a);
	write_op(ctx, "ra\n", OP_RA);
}

void	rb(t_ctx *ctx)
{
	rotate(&ctx->b);
	write_op(ctx, "rb\n", OP_RB);
}

void	rr(t_ctx *ctx)
{
	rotate(&ctx->a);
	rotate(&ctx->b);
	write_op(ctx, "rr\n", OP_RR);
}
