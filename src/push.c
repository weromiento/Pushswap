/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:53:21 by yflohic           #+#    #+#             */
/*   Updated: 2026/03/04 14:06:23 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	ft_printf(1, "pa\n");
	bench->count_pa++;
	bench->count_total++;
}

void	pb(t_stack **b, t_stack **a, t_bench *bench)
{
	push(b, a);
	ft_printf(1, "pb\n");
	bench->count_pb++;
	bench->count_total++;
}
