/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:24:21 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 11:25:32 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes the integer `nb` to the given file descriptor `fd`.
 * Handles the edge case of the minimum integer value, 
 * negative numbers, and recursively processes each digit
 * of the number.
 * 
 * @param nb The integer to be written.
 * @param fd The file descriptor to which the integer should be written.
 */
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	ft_putchar_fd('0' + (nb % 10), fd);
}
