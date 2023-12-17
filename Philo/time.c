/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:53:57 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/17 00:35:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_timestamp(t_philo philo, const char *message)
{
	struct timeval current_time;
	long micro_seconds;
	long seconds;
	long minutes;
	long hours;
	long days;
	long remainingSecondes;

	gettimeofday(&current_time, NULL);
	seconds = current_time.tv_sec;
	micro_seconds = current_time.tv_usec;
	days = seconds / (24 * 3600);
	remainingSecondes = seconds % (24 * 3600);
	hours = remainingSecondes / 3600;
	remainingSecondes %= 3600;
	minutes = remainingSecondes / 60;
	remainingSecondes %= 60;
	printf("%lu:%lu:%lu:%lu : %d %s", hours, minutes, remainingSecondes,
			micro_seconds, philo.philo_id, message);
}