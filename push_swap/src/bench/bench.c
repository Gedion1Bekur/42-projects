/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	total_ops(t_ctx *ctx)
{
	long	total;
	int		index;

	total = 0;
	index = 0;
	while (index < OP_COUNT)
		total += ctx->ops[index++];
	return (total);
}

static void	print_swaps_and_pushes(t_ctx *ctx)
{
	put_str_fd("[bench] sa: ", 2);
	put_nbr_fd(ctx->ops[OP_SA], 2);
	put_str_fd(" sb: ", 2);
	put_nbr_fd(ctx->ops[OP_SB], 2);
	put_str_fd(" ss: ", 2);
	put_nbr_fd(ctx->ops[OP_SS], 2);
	put_str_fd(" pa: ", 2);
	put_nbr_fd(ctx->ops[OP_PA], 2);
	put_str_fd(" pb: ", 2);
	put_nbr_fd(ctx->ops[OP_PB], 2);
	put_str_fd("\n", 2);
}

static void	print_rotations(t_ctx *ctx)
{
	put_str_fd("[bench] ra: ", 2);
	put_nbr_fd(ctx->ops[OP_RA], 2);
	put_str_fd(" rb: ", 2);
	put_nbr_fd(ctx->ops[OP_RB], 2);
	put_str_fd(" rr: ", 2);
	put_nbr_fd(ctx->ops[OP_RR], 2);
	put_str_fd(" rra: ", 2);
	put_nbr_fd(ctx->ops[OP_RRA], 2);
	put_str_fd(" rrb: ", 2);
	put_nbr_fd(ctx->ops[OP_RRB], 2);
	put_str_fd(" rrr: ", 2);
	put_nbr_fd(ctx->ops[OP_RRR], 2);
	put_str_fd("\n", 2);
}

void	print_bench(t_ctx *ctx)
{
	put_str_fd("[bench] disorder: ", 2);
	put_percent_fd(ctx->disorder, 2);
	put_str_fd("\n[bench] strategy: ", 2);
	put_str_fd(strategy_name(ctx), 2);
	put_str_fd(" / ", 2);
	put_str_fd(complexity_class(ctx), 2);
	put_str_fd("\n[bench] total_ops: ", 2);
	put_nbr_fd(total_ops(ctx), 2);
	put_str_fd("\n", 2);
	print_swaps_and_pushes(ctx);
	print_rotations(ctx);
}
