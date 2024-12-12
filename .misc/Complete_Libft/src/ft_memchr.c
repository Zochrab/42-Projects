/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:03:02 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @fn void *ft_memchr(const void *s, int c, size_t n)
 * 
 * @brief Locates the first occurrence of c in the memory block pointed to by s.
 * 
 * @param s A pointer to the memory block to search.
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * 
 * @return A pointer to the first occurrence of c in the memory block, or NULL if
 * the character is not found.
 */
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
