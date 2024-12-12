/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:28:13 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * The ft_strrchr() function returns a pointer to the last occurrence of the
 * character `c` in the string `s`.
 *
 * @param s the string to search in
 * @param c the character to search for
 * @return a pointer to the last occurrence of c in s, or NULL if c is not found
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	while (c > 127)
		c -= 128;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
