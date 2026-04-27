/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:56:55 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:30:22 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_flags
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
	char	*strategy;
}	t_flags;

typedef struct s_bench
{
	int		count_sa;
	int		count_sb;
	int		count_ss;
	int		count_pa;
	int		count_pb;
	int		count_ra;
	int		count_rb;
	int		count_rr;
	int		count_rra;
	int		count_rrb;
	int		count_rrr;
	int		count_total;
	float	dis;
}	t_bench;

int		syntax_error(char *str);
int		duplicate_error(t_stack *a, int n);
int		stack_len(t_stack *stack);
int		is_sorted(t_stack *a);
void	assign_index(t_stack *a);
void	free_stack(t_stack **stack);
void	free_print(t_stack **stack);
void	init_stack_a(t_stack **a, char **av);
void	error_exit(void);
void	parse_flags(int *start_index, int ac, char **av, t_flags *flags);
long	ft_atol(const char *str);
t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_middle(t_stack *stack);
void	print_bench(t_bench *bench, t_flags *flags);
void	print_strategy(t_flags *flags);

void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **b, t_stack **a, t_bench *bench);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

void	sort_three(t_stack **stack, t_bench *bench);
void	sort_five(t_stack **stack, t_stack **b, t_bench *bench);
void	short_sort(t_stack **a, t_stack **b, t_bench *bench);
void	simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	medium_sort(t_stack **a, t_stack **b, t_bench *bench);
void	complex_sort(t_stack **a, t_stack **b, t_bench *bench);
void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench, t_flags *flags);

#endif
