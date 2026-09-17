/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:26:25 by hcherif           #+#    #+#             */
/*   Updated: 2026/09/17 19:23:29 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				keep;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move
{
	int	a;
	int	b;
}	t_move;

typedef enum e_sort_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_sort_mode;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_ctx
{
	t_stack		*a;
	t_stack		*b;
	t_sort_mode	mode;
	int			bench;
	double		disorder;
	int			ops[OP_COUNT];
}	t_ctx;

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	assign_indexes(t_stack *stack);

int		parsing_int(char *str, int *value);
int		has_duplicate(t_stack *stack, int value);
int		is_space(char c);
int		has_space(char *str);
int		read_number(char **str, int *value);
int		parse_args(int argc, char **argv, t_stack **a);
int		parse_mode(char *arg, t_sort_mode *mode);
int		parse_flags(int argc, char **argv, t_ctx *ctx);

void	write_op(t_ctx *ctx, char *op, t_op id);
void	sa(t_ctx *ctx);
void	sb(t_ctx *ctx);
void	ss(t_ctx *ctx);
void	pa(t_ctx *ctx);
void	pb(t_ctx *ctx);
void	ra(t_ctx *ctx);
void	rb(t_ctx *ctx);
void	rr(t_ctx *ctx);
void	rra(t_ctx *ctx);
void	rrb(t_ctx *ctx);
void	rrr(t_ctx *ctx);

double	compute_disorder(t_stack *stack);
int		position_of_min(t_stack *stack);
int		position_of_max(t_stack *stack);
int		target_position(t_stack *a, int index);
void	sort_three(t_ctx *ctx);
void	rotate_min_to_top(t_ctx *ctx);
void	sort_small(t_ctx *ctx);
int		mark_lis(t_stack *stack, int size);
t_move	cheapest_move(t_ctx *ctx);
void	sort_stack(t_ctx *ctx);
void	sort_simple(t_ctx *ctx);
void	sort_medium(t_ctx *ctx);
void	sort_complex(t_ctx *ctx);
void	sort_adaptive(t_ctx *ctx);

void	put_str_fd(char *s, int fd);
void	put_nbr_fd(long n, int fd);
void	put_percent_fd(double ratio, int fd);
char	*strategy_name(t_ctx *ctx);
char	*complexity_class(t_ctx *ctx);
void	print_bench(t_ctx *ctx);

#endif
