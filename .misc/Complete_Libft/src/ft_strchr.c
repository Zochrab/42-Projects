/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:23:05 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * The strchr() function locates the first occurrence of c (converted to a char)
 * in the string pointed to by str.
 * 
 * @param str The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of c in the string str, or NULL if
 * the character is not found.
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	while (c > 127)
		c -= 128;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return ((char *)&str[i]);
		i++;
	}
	if (c == str[i])
		return ((char *)&str[i]);
	return (NULL);
}
