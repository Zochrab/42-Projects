/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:32:40 by zblume            #+#    #+#             */
/*   Updated: 2024/06/25 12:51:06 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			n = n * 10 + (nptr[i] - '0');
		else
			return (n * sign);
		i++;
	}
	return (n * sign);
}

void	send_bits(int pid, char *str, size_t len)
{
	size_t	i;
	size_t	bift;

	i = 0;
	while (i < len)
	{
		bift = 0;
		while (bift < 8)
		{
			if (str[i] & (1 << bift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bift++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments! Is %d must be 3\n", argc);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_bits(pid, str, ft_strlen(str));
	return (0);
}
