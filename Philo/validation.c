/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:55:46 by akabbadj          #+#    #+#             */
/*   Updated: 2023/12/06 06:27:55 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_exit(void)
{
	printf("error\n");
	exit(2);
}

int	is_digit(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

void	validate_number(char *array)
{
	int	i;

	i = 0;
	while (array[i] && array[i] == ' ')
		i++;
	if (array[i] == '+' || array[i] == '-')
		i++;
	while (array[i])
	{
		if (!is_digit(array[i]))
			free_and_exit();
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		free_and_exit();
	if (atoi(argv[1]) > 200 || atoi(argv[1]) < 0)
		free_and_exit();
	while (argv[i])
	{
		validate_number(argv[i]);
		if (atoi(argv[i]) <= 0)
			free_and_exit();
		i++;
	}
}
