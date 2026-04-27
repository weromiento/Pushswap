/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:32:04 by romgutie          #+#    #+#             */
/*   Updated: 2026/03/10 01:38:19 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_strategy_flag(char *arg, t_flags *flags, int *count)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		flags->simple = 1;
		(*count)++;
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		flags->medium = 1;
		(*count)++;
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		flags->complex = 1;
		(*count)++;
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		flags->adaptive = 1;
		(*count)++;
	}
	else if (ft_strcmp(arg, "--bench") == 0)
		flags->bench = 1;
	else
		error_exit();
}

void	parse_flags(int *start_index, int ac, char **av, t_flags *flags)
{
	int	i;
	int	strategy_count;

	ft_memset(flags, 0, sizeof(t_flags));
	i = 1;
	strategy_count = 0;
	while (i < ac && ft_strncmp(av[i], "--", 2) == 0)
	{
		set_strategy_flag(av[i], flags, &strategy_count);
		i++;
	}
	if (strategy_count > 1)
		error_exit();
	if (strategy_count == 0)
		flags->adaptive = 1;
	*start_index = i;
}
