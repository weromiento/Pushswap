/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:51:30 by romgutie          #+#    #+#             */
/*   Updated: 2025/12/09 19:14:39 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int fd)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10, fd);
	count += ft_putchar((nb % 10) + '0', fd);
	return (count);
}
