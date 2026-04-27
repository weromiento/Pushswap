/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 01:08:05 by romgutie          #+#    #+#             */
/*   Updated: 2025/12/12 13:57:18 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str, int fd)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)", fd));
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
