/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:11:03 by yflohic           #+#    #+#             */
/*   Updated: 2026/02/26 11:52:01 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;
	t_stack	*middle_node;

	middle_node = find_middle(*a);
	while (*a)
	{
		min_node = find_min(*a);
		while (min_node != *a)
		{
			if (min_node->value > middle_node->value)
				rra(a, bench);
			else
				ra(a, bench);
		}
		pb(b, a, bench);
	}
	while (*b)
		pa(a, b, bench);
}
