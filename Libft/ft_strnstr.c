/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:49:51 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 11:35:27 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn ft_strnstr
 * @brief Locates the first occurrence of the null-terminated string `little`
 * in the string `big`, where not more than `len` characters are searched.
 * @param big The string to search in.
 * @param little The string to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the first occurrence of little in big, or NULL if little
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*b;

	b = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return (b);
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		i++;
	}
	return (0);
}
