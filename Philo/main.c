/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:46:21 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/16 23:59:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_threads(t_philo *philos)
{
	int	i;
	int	nb_philos;
	int	nb_philos_times_eaten;

	i = 0;
	nb_philos_times_eaten = 0;
	nb_philos = philos[0].data->nb_philos;
	pthread_mutex_lock(&(philos->data->print_lock));
	while (i < nb_philos)
	{
		if (philos[i].is_dead)
		{
			printf("philo number %d died", i + 1);
			//free things.
			exit(0);
		}
		//if (philos[i].)
		i++;
	}
	pthread_mutex_lock(&(philos->data->print_lock));
	i = 0;
	while (i < nb_philos)
	{
		if (philos[i].times_eaten == (int)philos[i].data->nb_times_to_eat)
			nb_philos_times_eaten++;
		i++;
	}
	if (nb_philos_times_eaten == (int)philos[0].data->nb_times_to_eat)
	{
		printf("all philos have eaten %d number of times",
				philos[0].data->nb_philos);
		//free things
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;
	int		i;

	data = NULL;
	validate_args(argc, argv);
	data = malloc(sizeof(t_data));
	init_data(argv, data);
	philos = malloc(sizeof(t_philo) * data->nb_philos);
	init_philos(data, philos);
	init_mutex(data);
	create_threads(philos);
	join_threads(philos);
	monitor_threads(philos);
	pthread_mutex_destroy(&(data->print_lock));
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&(data->forks_lock[i]));
		i++;
	}
	return (0);
}
