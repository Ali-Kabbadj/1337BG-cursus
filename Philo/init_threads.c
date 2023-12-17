/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:59:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/15 03:21:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(data->print_lock), NULL);
	data->forks_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&(data->forks_lock[i]), NULL);
		i++;
	}
}

void	create_threads(t_philo *philos)
{
	int			i;
	pthread_t	thread;
	int			nb_philos;

	i = 0;
	nb_philos = philos[0].data->nb_philos;
	while (i < nb_philos)
	{
		pthread_create(&thread, NULL, routine, (void *)(&philos[i]));
		philos[i].thread_id = thread;
		i++;
	}
}

void	join_threads(t_philo *philos)
{
	int	i;
	int	nb_philos;

	i = 0;
	nb_philos = philos[i].data->nb_philos;
	while (i < nb_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		//printf("thread joint : %d\n", data[i - 1].nb_philo);
		i++;
	}
}
