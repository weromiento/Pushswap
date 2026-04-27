/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:24 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:43:24 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

float	count_mistakes(t_stack **stack, t_stack *start)
{
	float	mistakes;
	float	total_pairs;
	float	i;
	t_stack	*increment;

	mistakes = 0;
	total_pairs = 0;
	while ((*stack)->next)
	{
		increment = *stack;
		i = (*stack)->value;
		while ((*stack)->next)
		{
			total_pairs++;
			if (i > (*stack)->next->value)
				mistakes++;
			*stack = (*stack)->next;
		}
		*stack = increment;
		*stack = (*stack)->next;
	}
	*stack = start;
	return (mistakes / total_pairs);
}

float	disorder(t_stack **stack)
{
	t_stack	*start;

	if (!(*stack) || !(*stack)->next)
		return (0);
	start = *stack;
	return (count_mistakes(stack, start));
}

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench, t_flags *flags)
{
	if (bench->dis != 0)
	{
		if (stack_len(*a) == 2 || stack_len(*a) == 3 || stack_len(*a) == 5)
		{
			flags->strategy = "O(1)";
			short_sort(a, b, bench);
		}
		else if (bench->dis < 0.2)
		{
			flags->strategy = "O(n²)";
			simple_sort(a, b, bench);
		}
		else if (bench->dis < 0.5)
		{
			flags->strategy = "O(n√n)";
			medium_sort(a, b, bench);
		}
		else
		{
			flags->strategy = "O(n log n)";
			complex_sort(a, b, bench);
		}
	}
}

void	run_sort(t_stack **a, t_stack **b, t_flags *flags, t_bench *bench)
{
	if (is_sorted(*a))
		return ;
	if (flags->simple)
		simple_sort(a, b, bench);
	else if (flags->medium)
		medium_sort(a, b, bench);
	else if (flags->complex)
		complex_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench, flags);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench	bench;
	int		start_index;

	a = NULL;
	b = NULL;
	ft_memset(&bench, 0, sizeof(t_bench));
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	parse_flags(&start_index, ac, av, &flags);
	if (start_index >= ac)
		return (0);
	if ((ac - start_index) == 1)
		init_stack_a(&a, ft_split(av[start_index], ' '));
	else
		init_stack_a(&a, av + start_index);
	bench.dis = disorder(&a);
	run_sort(&a, &b, &flags, &bench);
	if (flags.bench)
		print_bench(&bench, &flags);
	free_stack(&a);
	return (0);
}
