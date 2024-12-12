/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:56:10 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief Counts the number of words in a string.
 *
 * @param s The string in which to count words.
 * @param c The character to use as a delimiter.
 * @return The number of words in the string.
 */
static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A pointer to an array of substrings.
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	str = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			str[k] = ft_substr(s, i, j);
			i += j;
			k++;
		}
		else
			i++;
	}
	str[k] = NULL;
	return (str);
}
