/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from || !to)
		return ;
	node = *from;
	*from = node->next;
	node->next = *to;
	*to = node;
}

void	pa(t_ctx *ctx)
{
	push(&ctx->b, &ctx->a);
	write_op(ctx, "pa\n", OP_PA);
}

void	pb(t_ctx *ctx)
{
	push(&ctx->a, &ctx->b);
	write_op(ctx, "pb\n", OP_PB);
}
