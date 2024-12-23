/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:03:02 by zblume            #+#    #+#             */
/*   Updated: 2023/11/17 16:05:27 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	pos;
	unsigned char	*a;

	a = (unsigned char *)s;
	pos = 0;
	while (pos < n)
	{
		if (a[pos] == (unsigned char)c)
			return (a + pos);
		pos ++;
	}
	return (0);
}
