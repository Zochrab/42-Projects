/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:28 by zblume            #+#    #+#             */
/*   Updated: 2024/12/01 14:49:04 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	taking_forks(t_philo *philo)
{
	t_data	*data;
	int		left_fork;
	int		right_fork;

	data = philo->data;
	left_fork = philo->id;
	right_fork = (philo->id + 1) % data->num_philosophers;
	if (philo->id  == 1)
	{
		pthread_mutex_lock(&data->forks[left_fork]);
		message(philo, FORK);
		pthread_mutex_lock(&data->forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&data->forks[right_fork]);
		message(philo, FORK);
		pthread_mutex_lock(&data->forks[left_fork]);
	}
	message(philo, FORK);
}

void	sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	message(philo, SLEEP);
	usleep(data->time_to_sleep * 1000);
}

void	done_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->forks[philo->id]);
	pthread_mutex_unlock(&data->forks[(philo->id + 1)
		% data->num_philosophers]);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	taking_forks(philo);
	message(philo, EAT);
	pthread_mutex_lock(&data->meal_check);
	philo->last_meal_time = get_runtime(data);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_check);
	usleep(data->time_to_eat * 1000);
	done_eating(philo);
}

void	thinking(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	message(philo, THINK);
	usleep(((data->time_to_die - data->time_to_eat - data->time_to_sleep) * 0.75) * 1000);
}
