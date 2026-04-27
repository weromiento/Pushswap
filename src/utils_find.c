/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:06:57 by yflohic           #+#    #+#             */
/*   Updated: 2026/02/26 11:28:22 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	int		min_value;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	int		max_value;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_middle(t_stack *stack)
{
	t_stack	*mid_node;
	int		mid_value;

	if (!stack)
		return (NULL);
	mid_node = stack;
	mid_value = stack_len(stack) / 2;
	while (mid_value > 1)
	{
		stack = stack->next;
		mid_value--;
	}
	mid_node = stack;
	return (mid_node);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
