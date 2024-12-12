/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:17 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 11:31:39 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of the
 * string.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be removed from the string.
 * @return The trimmed string, or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	e = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[s]) && s <= e)
		s++;
	if (s > e)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[e]) && e >= 0)
		e--;
	str = (char *)malloc(e - s + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[s], e - s + 2);
	return (str);
}
