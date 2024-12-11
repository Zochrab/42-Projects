/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:01:10 by zblume            #+#    #+#             */
/*   Updated: 2024/11/30 17:22:41 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	message(t_philo *philo, char *message)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->msg);
	pthread_mutex_lock(&data->dead_check);
	if (data->is_dead == 0)
		printf(GREEN"%lld"RESET" %d %s\n",
			get_runtime(philo->data), philo->id + 1, message);
	pthread_mutex_unlock(&data->dead_check);
	pthread_mutex_unlock(&data->msg);
	return (0);
}

long long	get_timestamp(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000);
	time += (tv.tv_usec / 1000);
	return (time);
}

long long	get_runtime(t_data *data)
{
	return (get_timestamp() - data->start_time);
}

long long	ft_atoi(const char *nptr)
{
	long long	i;
	long long	n;
	int			sign;

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
