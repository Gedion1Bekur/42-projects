/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/18 12:00:38 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	write_op(t_ctx *ctx, char *op, t_op id)
{
	int	length;

	ctx->ops[id]++;
	length = 0;
	while (op[length])
		length++;
	write(1, op, length);
}

static int	swap(t_stack **stack)
{
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
	return (1);
}

void	sa(t_ctx *ctx)
{
	if (swap(&ctx->a))
		write_op(ctx, "sa\n", OP_SA);
}

void	sb(t_ctx *ctx)
{
	if (swap(&ctx->b))
		write_op(ctx, "sb\n", OP_SB);
}

void	ss(t_ctx *ctx)
{
	int	a_changed;
	int	b_changed;

	a_changed = swap(&ctx->a);
	b_changed = swap(&ctx->b);
	if (a_changed || b_changed)
		write_op(ctx, "ss\n", OP_SS);
}
