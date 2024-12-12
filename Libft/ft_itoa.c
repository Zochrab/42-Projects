/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:08:46 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 11:23:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn		ft_get_number_length
 * 
 * @brief	Calculates the length of an integer value.
 * 
 * @param	n	The integer value to be converted.
 * 
 * @return The length of the integer value.
 */
static int	ft_get_number_length(int n)
{
	int	length;
	int	abs_val;

	length = 0;
	abs_val = n;
	if (abs_val < 0)
	{
		length++;
		abs_val = -abs_val;
	}
	while (abs_val > 0)
	{
		abs_val = abs_val / 10;
		length++;
	}
	return (length);
}

/**
 * @fn		ft_fill_string
 * 
 * @brief	Fills a string with the digits of an integer value.
 * 
 * @param	str	The string to be filled.
 * @param	n	The integer value to be converted.
 * @param	length	The length of the string.
 * 
 * @return None
 */
static void	ft_fill_string(char *str, int n, int length)
{
	int	i;
	int	cmp;

	i = length - 1;
	cmp = 0;
	length++;
	if (n < 0)
	{
		str[0] = 45;
		n = -n;
		cmp = 1;
	}
	while (i >= cmp)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[length -1] = '\0';
}

/**
 * @fn		ft_itoa
 * 
 * @brief	Converts an integer value to a string of digits.
 * 
 * @param n The integer value to be converted.
 * 
 * @return	A pointer to the string of digits representing the integer value.
 */
char	*ft_itoa(int n)
{
	int		length;
	char	*str;

	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	length = ft_get_number_length(n);
	str = (char *)ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_fill_string(str, n, length);
	return (str);
}
