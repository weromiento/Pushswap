/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:29 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:06:36 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	ft_printf(1, "ra\n");
	bench->count_ra++;
	bench->count_total++;
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	ft_printf(1, "rb\n");
	bench->count_rb++;
	bench->count_total++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
	bench->count_rr++;
	bench->count_total++;
}
