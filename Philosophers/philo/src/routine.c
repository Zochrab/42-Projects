/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:42:24 by zblume            #+#    #+#             */
/*   Updated: 2024/11/30 17:56:09 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_local_death(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->dead_check);
	if (data->is_dead == 1 || !philo->is_alive)
	{
		pthread_mutex_unlock(&data->dead_check);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_check);
	return (0);
}

int	check_satiety(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->meal_check);
	if (data->meals_required > 0
		&& philo->meals_eaten >= data->meals_required)
	{
		data->finished++;
		pthread_mutex_unlock(&data->meal_check);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_check);
	return (0);
}


int	delay(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->id % 2 == 0)
	{
		if (check_local_death(data, philo))
			return (-1);
		thinking(philo);
	}
	return (0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_ptr;
	data = philo->data;
	if (delay(philo) == -1)
		return (NULL);
	while (1)
	{
		if (check_satiety(data, philo) == 1)
			break ;
		//if (check_local_death(data, philo))
		//	break ;
		eating(philo);
		//if (check_local_death(data, philo))
		//	break ;
		sleeping(philo);
		if (check_local_death(data, philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}

