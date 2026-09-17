/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_ctx *ctx, int bit, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if ((ctx->a->index >> bit) & 1)
			ra(ctx);
		else
			pb(ctx);
		index++;
	}
	while (ctx->b)
		pa(ctx);
}

void	sort_complex(t_ctx *ctx)
{
	int	bit;
	int	size;

	if (stack_size(ctx->a) <= 5)
	{
		sort_small(ctx);
		return ;
	}
	assign_indexes(ctx->a);
	size = stack_size(ctx->a);
	bit = 0;
	while ((size - 1) >> bit)
	{
		radix_pass(ctx, bit, size);
		bit++;
	}
}
