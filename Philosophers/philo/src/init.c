/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:05:46 by zblume            #+#    #+#             */
/*   Updated: 2024/11/22 14:09:47 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_mutexes(t_data *data)
{
	int		i;

	i = 0;
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->meal_check, NULL);
	pthread_mutex_init(&data->dead_check, NULL);
	while (i < data->num_philosophers)
		pthread_mutex_init(&data->forks[i++], NULL);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philosophers = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->meals_required = atoi(argv[5]);
	else
		data->meals_required = -1;
	data->is_dead = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	data->philo = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->forks || !data->philo)
		return (NULL);
	data->start_time = get_timestamp();
	init_mutexes(data);
	return (data);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		data->philo[i].id = i;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal_time = get_runtime(data);
		data->philo[i].data = data;
		data->philo[i].is_alive = 1;
		i++;
	}
	data->finished = 0;
}

void	cleanup_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->meal_check);
	free(data->forks);
	free(data->philo);
	free(data);
}
