/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_to_top(t_ctx *ctx)
{
	int	position;
	int	size;

	position = position_of_min(ctx->a);
	size = stack_size(ctx->a);
	if (position <= size / 2)
		while (position-- > 0)
			ra(ctx);
	else
		while (position++ < size)
			rra(ctx);
}

void	sort_small(t_ctx *ctx)
{
	while (stack_size(ctx->a) > 3)
	{
		rotate_min_to_top(ctx);
		pb(ctx);
	}
	if (stack_size(ctx->a) == 3)
		sort_three(ctx);
	else if (stack_size(ctx->a) == 2 && ctx->a->value > ctx->a->next->value)
		sa(ctx);
	while (ctx->b)
		pa(ctx);
}
