/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:25:06 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/18 11:56:08 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_ctx(t_ctx *ctx)
{
	int	index;

	ctx->a = NULL;
	ctx->b = NULL;
	ctx->mode = MODE_ADAPTIVE;
	ctx->bench = 0;
	ctx->disorder = 0.0;
	index = 0;
	while (index < OP_COUNT)
		ctx->ops[index++] = 0;
}

static int	read_input(int argc, char **argv, t_ctx *ctx)
{
	int	start;

	start = parse_flags(argc, argv, ctx);
	if (start < 0)
		return (-1);
	if (start >= argc)
		return (-1);
	if (!parse_args(argc - start, argv + start, &ctx->a))
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		status;

	init_ctx(&ctx);
	if (argc == 1)
		return (0);
	status = read_input(argc, argv, &ctx);
	if (status < 0)
	{
		stack_clear(&ctx.a);
		put_str_fd("Error\n", 2);
		return (1);
	}
	if (status == 0)
		return (0);
	ctx.disorder = compute_disorder(ctx.a);
	if (!stack_is_sorted(ctx.a))
		sort_stack(&ctx);
	if (ctx.bench)
		print_bench(&ctx);
	stack_clear(&ctx.a);
	stack_clear(&ctx.b);
	return (0);
}
