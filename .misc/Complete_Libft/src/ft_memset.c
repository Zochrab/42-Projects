/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:28:12 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief Fills the first `n` bytes of the memory area pointed to by `s` with 
 *        the constant byte `c`.
 * 
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to fill the memory area with, converted to an 
 *          unsigned char.
 * @param n The number of bytes to fill.
 * 
 * @return A pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*new;

	new = (char *)s;
	i = 0;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	return (s);
}
