/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:06 by zblume            #+#    #+#             */
/*   Updated: 2024/12/12 15:01:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/** 
 * This function is used to set a block of memory to zero.
 * 
 * @param s A pointer to the memory block to be set to zero.
 * @param n The number of bytes to be set to zero.
 * 
 * @return None
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
