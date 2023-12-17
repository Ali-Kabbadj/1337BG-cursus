/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:44:06 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/14 23:51:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].philo_id = i + 1;
		philos[i].left_fork = i;
		if (i == data->nb_philos - 1)
			philos[i].right_fork = 0;
		else
			philos[i].right_fork = i + 1;
		philos[i].is_dead = 0;
		philos[i].data = data;
		philos[i].time_eating = data->time_to_eat;
		i++;
	}
}

void	init_data(char **argv, t_data *data)
{
	data->nb_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		data->nb_times_to_eat = atoi(argv[5]);
	else
		data->nb_times_to_eat = TIME_TO_EAT;
}
