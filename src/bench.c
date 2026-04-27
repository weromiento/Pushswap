/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 00:31:22 by romgutie          #+#    #+#             */
/*   Updated: 2026/03/05 00:31:22 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_strategy(t_flags *flags)
{
	ft_printf(2, "[bench] strategy: ");
	if (flags->simple)
		ft_printf(2, "simple / O(n²)\n");
	else if (flags->medium)
		ft_printf(2, "medium / O(n√n)\n");
	else if (flags->complex)
		ft_printf(2, "complex / O(n log n)\n");
	else if (flags->adaptive && !(flags->strategy == NULL))
		ft_printf(2, "adaptive / %s\n", flags->strategy);
	else
		ft_printf(2, "adaptive / none\n");
}

void	print_bench(t_bench *bench, t_flags *flags)
{
	ft_printf(2, "[bench] disorder: %.2f%%\n", bench->dis * 100);
	print_strategy(flags);
	ft_printf(2, "[bench] total_ops: %d\n", bench->count_total);
	ft_printf(2, "[bench] sa: %d  ", bench->count_sa);
	ft_printf(2, "sb: %d  ", bench->count_sb);
	ft_printf(2, "ss: %d  ", bench->count_ss);
	ft_printf(2, "pa: %d  ", bench->count_pa);
	ft_printf(2, "pb: %d\n", bench->count_pb);
	ft_printf(2, "[bench] ra: %d  ", bench->count_ra);
	ft_printf(2, "rb: %d  ", bench->count_rb);
	ft_printf(2, "rr: %d  ", bench->count_rr);
	ft_printf(2, "rra: %d  ", bench->count_rra);
	ft_printf(2, "rrb: %d  ", bench->count_rrb);
	ft_printf(2, "rrr: %d\n", bench->count_rrr);
}
