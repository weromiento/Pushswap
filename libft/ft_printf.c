/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yflohic <yflohic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:33:38 by romgutie          #+#    #+#             */
/*   Updated: 2026/03/04 14:38:57 by yflohic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	get_precision(const char *format, int *i)
{
	int	precision;

	precision = 6;
	if (format[*i] == '.')
	{
		(*i)++;
		precision = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			precision = precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return (precision);
}

int	ft_dispatch(const char *format, int *i, va_list args, int fd)
{
	int	precision;

	precision = get_precision(format, i);
	if (format[*i] == 'c')
		return (ft_putchar(va_arg(args, int), fd));
	else if (format[*i] == 's')
		return (ft_putstr(va_arg(args, char *), fd));
	else if (format[*i] == 'p')
		return (ft_putptr(va_arg(args, void *), fd));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return (ft_putnbr(va_arg(args, int), fd));
	else if (format[*i] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), fd));
	else if (format[*i] == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0, fd));
	else if (format[*i] == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, fd));
	else if (format[*i] == 'f')
		return (ft_putfloat(va_arg(args, double), fd, precision));
	else if (format[*i] == '%')
		return (ft_putchar('%', fd));
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_dispatch(format, &i, args, fd);
		}
		else
		{
			write(fd, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
