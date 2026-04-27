/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:09:18 by yflohic           #+#    #+#             */
/*   Updated: 2026/02/26 11:40:42 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack, t_bench *bench)
{
	t_stack	*max_node;

	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack, bench);
	else if (max_node == (*stack)->next)
		rra(stack, bench);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, bench);
}

void	sort_five(t_stack **stack, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;
	int		i;

	i = 2;
	while (i > 0)
	{
		min_node = find_min(*stack);
		if (min_node == (*stack)->next
			|| min_node == (*stack)->next->next)
		{
			while (min_node != *stack)
				ra(stack, bench);
		}
		while (min_node != *stack)
			rra(stack, bench);
		pb(b, stack, bench);
		i--;
	}
	sort_three(stack, bench);
	pa(stack, b, bench);
	pa(stack, b, bench);
}

void	short_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a, bench);
	else if (len == 3)
		sort_three(a, bench);
	else if (len == 5)
		sort_five(a, b, bench);
}
