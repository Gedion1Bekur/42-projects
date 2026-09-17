/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:00:00 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_ctx *ctx)
{
	if (stack_size(ctx->a) <= 5)
	{
		sort_small(ctx);
		return ;
	}
	if (ctx->disorder < 0.2)
		sort_simple(ctx);
	else if (ctx->disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}

void	sort_stack(t_ctx *ctx)
{
	if (ctx->mode == MODE_SIMPLE)
		sort_simple(ctx);
	else if (ctx->mode == MODE_MEDIUM)
		sort_medium(ctx);
	else if (ctx->mode == MODE_COMPLEX)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
}
