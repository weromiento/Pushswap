/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romgutie <romgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:30:39 by romgutie          #+#    #+#             */
/*   Updated: 2025/11/11 20:31:23 by romgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	int		len;

	len = get_len(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	nbr = n;
	if (nbr < 0)
	{
		s[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		s[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (s);
}
