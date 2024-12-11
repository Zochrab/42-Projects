/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:41:39 by zblume            #+#    #+#             */
/*   Updated: 2024/11/30 18:22:54 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	validate_arguments(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf(USAGE, argv[0]);
		return (1);
	}
	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			printf(USAGE, argv[0]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_philosopher_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_create(&data->philo[i].thread_id,
				NULL, &routine, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	join_philosopher_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
		pthread_join(data->philo[i++].thread_id, NULL);
}

void	one_philo(t_data *data)
{
	printf(GREEN"%lld"RESET" 1 "FORK"\n", get_runtime(data));
	usleep(data->time_to_die * 1000);
	printf(RED"%lld 1 died"RESET"\n", get_runtime(data));
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	monitor_thread;

	if (validate_arguments(argc, argv))
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (data->num_philosophers == 1)
	{
		one_philo(data);
		cleanup_data(data);
		return (1);
	}
	init_philo(data);
	if (create_philosopher_threads(data) != 0)
		return (1);
	if (pthread_create(&monitor_thread, NULL, &monitor_philosophers, data) != 0)
		return (1);
	join_philosopher_threads(data);
	pthread_join(monitor_thread, NULL);
	cleanup_data(data);
	return (0);
}
