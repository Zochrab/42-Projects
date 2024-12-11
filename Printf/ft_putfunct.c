/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:01 by zblume            #+#    #+#             */
/*   Updated: 2023/12/14 14:46:10 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_putnbr(int nb)
{
	size_t	size;
	int		sign;

	sign = 0;
	size = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		sign += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		size = ft_putnbr((nb / 10));
	size += ft_putchar('0' + (nb % 10));
	return (size + sign);
}

size_t	ft_putunsigned(unsigned int nb)
{
	size_t	size;

	size = 0;
	if (nb >= 10)
		size = ft_putunsigned((nb / 10));
	size += ft_putchar('0' + (nb % 10));
	return (size);
}
