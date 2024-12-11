/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:39 by zblume            #+#    #+#             */
/*   Updated: 2024/01/15 12:32:59 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *trim, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!trim)
	{
		trim = (char *)malloc(1 * sizeof(char));
		trim[0] = '\0';
	}
	if (!trim || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(trim) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (trim)
		while (trim[++i] != '\0')
			str[i] = trim[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(trim) + ft_strlen(buff)] = '\0';
	clean_pointer(&trim);
	return (str);
}

void	clean_pointer(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
