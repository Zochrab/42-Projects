/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:32:04 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 11:27:07 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends the string `src` to the end of `dest` up to `size` - 1 characters
 * and NUL-terminates the result. The function returns the total length of the
 * string it tried to create, which is the initial length of `dest` plus the
 * length of `src`.
 *
 * @param dest The destination string to which `src` will be appended.
 * @param src The source string to be appended to `dest`.
 * @param size The full size of the destination buffer.
 * @return The length of the string that was attempted to be created.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*src1;

	src1 = (char *)src;
	i = 0;
	while (i < size && *dest)
	{
		dest++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen((char *)src));
	j = 0;
	while (src1[j])
	{
		if (j < size - i - 1)
			*dest++ = src1[j];
		j++;
	}
	*dest = 0;
	return (j + i);
}
