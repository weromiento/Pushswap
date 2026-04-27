/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:34 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:06:44 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	ft_printf(1, "sa\n");
	bench->count_sa++;
	bench->count_total++;
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	ft_printf(1, "sb\n");
	bench->count_sb++;
	bench->count_total++;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
	bench->count_ss++;
	bench->count_total++;
}
