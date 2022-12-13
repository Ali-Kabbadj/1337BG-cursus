/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:23:00 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/13 00:23:04 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_duplicates(int *digits, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (digits[i] == digits[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_digits(int *digits, int count, char *argv[])
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (digits[i] > 9 || digits[i] < -9 || (digits[i] == 0 && *argv[i
				+ 1] != '0'))
			return (0);
		i++;
	}
	return (1);
}
