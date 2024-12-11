/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:32:37 by zblume            #+#    #+#             */
/*   Updated: 2024/06/25 12:51:09 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	translator(int sig)
{
	static int		i;
	static int		bit;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to zblume's server!\n");
	ft_printf("My PID is %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, translator);
		signal(SIGUSR1, translator);
		pause();
	}
	return (0);
}
