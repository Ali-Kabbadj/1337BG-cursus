/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:07:35 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/17 00:06:24 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (((long long)current_time.tv_sec * 1000000) + current_time.tv_usec);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&(philo->data->forks_lock[(philo->philo_id) - 1]));
	if (philo->philo_id == 5)
	{
		print_timestamp(*philo, "is eating\n");
	}
	usleep(500);
	if (philo->philo_id == 7)
	{
		print_timestamp(*philo, "is eating\n");
	}
	pthread_mutex_unlock(&(philo->data->forks_lock[(philo->philo_id) - 1]));
	return (NULL);
}

