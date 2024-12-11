/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:20 by zblume            #+#    #+#             */
/*   Updated: 2024/11/30 16:38:09 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//LIBRARIES
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <limits.h>
# include <time.h>

//STRUCTS
typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	long			last_meal_time;
	int				meals_eaten;
	int				is_alive;
	struct s_data	*data;

}	t_philo;

typedef struct s_start
{
	long long	start_time;
}	t_start;

typedef struct s_data
{
	long long		num_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		meals_required;
	int				is_dead;
	int				finished;
	long long		start_time;
	pthread_mutex_t	msg;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	dead_check;
	t_philo			*philo;
}	t_data;

//PROTOTYPES

// VALIDATE
int					validate_input(char **argv);
long long			ft_atoi(const char *str);
// INIT
void				init_philo(t_data *data);
t_data				*init_data(int argc, char **argv);
//UTIL
long long			get_runtime(t_data *data);
long long			get_timestamp(void);
int					message(t_philo *philo, char *message);
//ROUTINE
void				sleeping(t_philo *philo);
void				taking_forks(t_philo *philo);
void				eating(t_philo *philo);
void				thinking(t_philo *philo);
void				*routine(void *philo_ptr);
// MONITOR
int					check_all_full(t_data *data);
void				*monitor_philosophers(void *data_ptr);
// FREE
void				cleanup_data(t_data *data);

//DEFINES
# define USAGE "Wrong Number of Arguments!\n\
USAGE: %s\n\
[Number of philosophers]\n\
[Time to die in ms]\n\
[Time to eat in ms]\n\
[Time to sleep in ms]\n\
[Number of times each philosopher must eat (optional)]\n"

# define SLEEP "is sleeping"

# define EAT "is eating"

# define THINK "is thinking"

# define DIED "\033[31mdied\033[0m"

# define FORK "has taken a fork"

# define INVALID_INPUT "Error!\nInvalid input!\n"

//COLORS
# define RESET    "\033[0m"
# define RED      "\033[31m"    
# define GREEN    "\033[32m"    
# define YELLOW   "\033[33m"    
# define BLUE     "\033[34m"    
# define MAGENTA  "\033[35m"    
# define CYAN     "\033[36m"    
# define WHITE    "\033[37m"

#endif
