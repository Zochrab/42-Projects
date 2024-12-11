/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:50:13 by zblume            #+#    #+#             */
/*   Updated: 2023/11/29 13:50:13 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

size_t			ft_strlen(const char *str);
size_t			ft_putchar(char c);
size_t			ft_putstr(char *s);
size_t			ft_putnbr(int nb);
size_t			ft_putunsigned(unsigned int nb);
size_t			ft_hex_convert(unsigned long num, int size);
size_t			ft_putptr(void *ptr);
int				ft_printf(const char *str, ...);

#endif