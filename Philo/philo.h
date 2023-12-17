/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:10:27 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/16 23:52:17 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TIME_TO_EAT 100

typedef struct s_data
{
	int				nb_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			nb_times_to_eat;
	pthread_mutex_t	*forks_lock;
	pthread_mutex_t	print_lock;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				left_fork;
	int				right_fork;
	int				is_dead;
	int				time_eating;
	int				times_eaten;
	t_data			*data;
}					t_philo;

/* validation */
void				free_and_exit(void);
int					is_digit(char c);
void				validate_number(char *array);
void				validate_args(int argc, char **argv);

/* initialization */

void				init_philos(t_data *data, t_philo *philos);
void				init_data(char **argv, t_data *data);

/* thread_creation */
void				init_mutex(t_data *data);
void				create_threads(t_philo *philos);
void				join_threads(t_philo *data);

/* routine */
void				*routine(void *args);

/* time */
void				print_timestamp(t_philo philo, const char *message);

#endif