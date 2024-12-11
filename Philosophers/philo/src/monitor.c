/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:18 by zblume            #+#    #+#             */
/*   Updated: 2024/11/30 18:24:19 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


int	check_death(t_data *data)
{
	int		i;
	long	current_time;

	i = 0;
	current_time = get_runtime(data);
	pthread_mutex_lock(&data->dead_check);
	pthread_mutex_lock(&data->meal_check);
	while (i < data->num_philosophers)
	{
		if (current_time - data->philo[i].last_meal_time > data->time_to_die)
		{
			printf(GREEN"%lld"RESET" %d %s\n", get_runtime(data), i + 1, DIED);
			data->is_dead = 1; 
			data->philo[i].is_alive = 0;
			pthread_mutex_unlock(&data->meal_check);
			pthread_mutex_unlock(&data->dead_check);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal_check);
	pthread_mutex_unlock(&data->dead_check);
	return (0);
}

int	check_all_full(t_data *data)
{
	int		i;
	int		all_full;

	i = 0;
	all_full = 0;
	pthread_mutex_lock(&data->meal_check);
	while (i < data->num_philosophers)
	{
		if (data->philo[i].meals_eaten >= data->meals_required)
			all_full++;
		if (all_full == data->num_philosophers)
		{
			data->is_dead = 1;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal_check);
	return (all_full);
}

void	*monitor_philosophers(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	while (1)
	{
		if (check_death(data))
			break ;
		if (data->meals_required > -1
			&& check_all_full(data) == data->num_philosophers)
			break ;
		pthread_mutex_lock(&data->dead_check);
		if (data->finished >= data->num_philosophers)
		{
			data->is_dead = 1;
			pthread_mutex_unlock(&data->dead_check);
			break ;
		}
		pthread_mutex_unlock(&data->dead_check);
		usleep(100);
	}
	return (NULL);
}

