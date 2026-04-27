/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:52:31 by yflohic           #+#    #+#             */
/*   Updated: 2026/02/27 16:43:26 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_chunks(t_stack **a, t_stack **b, int len_chunk, t_bench *bench)
{
	int	size;
	int	cpt;
	int	chunk_max;

	size = stack_len(*a);
	cpt = 0;
	chunk_max = len_chunk;
	while (cpt < size && *a)
	{
		if ((*a)->index < chunk_max)
		{
			pb(b, a, bench);
			cpt++;
			if (*b && (*b)->index > chunk_max)
				rb(b, bench);
		}
		else
			ra(a, bench);
		if (cpt == chunk_max)
			chunk_max += len_chunk;
	}
}

int	max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	if (!stack)
		return (0);
	max = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	push_back(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = max_pos(*b);
		size = stack_len(*b);
		if (size < 2)
			pa(a, b, bench);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, bench);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	c_count;
	int	c_size;

	assign_index(*a);
	size = stack_len(*a);
	c_count = ft_sqrt(size);
	c_size = size / c_count;
	push_chunks(a, b, c_size, bench);
	push_back(a, b, bench);
}
