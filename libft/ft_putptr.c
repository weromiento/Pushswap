/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:47:19 by romgutie          #+#    #+#             */
/*   Updated: 2026/02/04 13:12:43 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_ptr(unsigned long long n, int fd)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16, fd);
	count += ft_putchar(base[n % 16], fd);
	return (count);
}

int	ft_putptr(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	if (!ptr)
		return (ft_putstr("(nil)", fd));
	addr = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr("0x", fd);
	count += ft_puthex_ptr(addr, fd);
	return (count);
}
