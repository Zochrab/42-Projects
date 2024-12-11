/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:11:16 by zblume            #+#    #+#             */
/*   Updated: 2023/11/29 13:50:25 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex_convert(unsigned long num, int size)
{
	char			*hex;
	int				len;

	len = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (size == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
	{
		len = ft_hex_convert(num / 16, size);
		len += ft_hex_convert(num % 16, size);
	}
	else
		len += ft_putchar((hex[num]));
	return (len);
}

size_t	ft_putptr(void *ptr)
{
	size_t	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	ft_putchar('0');
	ft_putchar('x');
	len = ft_hex_convert((unsigned long)ptr, 0);
	return (len + 2);
}
