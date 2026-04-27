/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:14 by yflohic           #+#    #+#             */
/*   Updated: 2026/02/25 15:53:48 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

void	complex_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	assign_index(*a);
	size = stack_len(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = size;
		while (i-- > 0)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, bench);
			else
				pb(b, a, bench);
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
}
