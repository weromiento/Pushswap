/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:27 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:06:30 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	ft_printf(1, "rra\n");
	bench->count_rra++;
	bench->count_total++;
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	ft_printf(1, "rrb\n");
	bench->count_rrb++;
	bench->count_total++;
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf(1, "rrr\n");
	bench->count_rrr++;
	bench->count_total++;
}
