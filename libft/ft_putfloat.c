/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:03:07 by romgutie          #+#    #+#             */
/*   Updated: 2026/03/04 23:03:07 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_decimal(double decimal, int precision, int fd)
{
	int	count;
	int	mult;
	int	i;

	count = 0;
	mult = 1;
	i = 0;
	while (i++ < precision)
		mult *= 10;
	decimal = decimal * mult + 0.5;
	i = precision - 1;
	while (i-- > 0 && (int)decimal < (mult / 10))
	{
		count += ft_putchar('0', fd);
		mult /= 10;
	}
	count += ft_putnbr((int)decimal, fd);
	return (count);
}

int	ft_putfloat(double f, int fd, int precision)
{
	int		count;
	int		integer_part;

	count = 0;
	if (f < 0)
	{
		count += ft_putchar('-', fd);
		f = -f;
	}
	integer_part = (int)f;
	count += ft_putnbr(integer_part, fd);
	count += ft_putchar('.', fd);
	count += put_decimal(f - integer_part, precision, fd);
	return (count);
}
