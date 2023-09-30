/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:20 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:01:57 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/args_validation/args_validation.h"
#include "../../includes/struct.h"
#include "../../libs/libft/libft.h"
#include <limits.h>
#include <stdlib.h>

void	to_int_array(char **argv, int *integers)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 1;
	j = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((argv[i][k] == '-' && ft_isdigit(argv[i][k + 1]))
				|| (ft_isdigit(argv[i][k])))
			{
				integers[j] = ft_atoi_no_overflow(&argv[i][k], integers);
				j++;
				while (ft_isdigit(argv[i][k]) || argv[i][k] == '-')
					k++;
			}
			else
				k++;
		}
		i++;
	}
}

size_t	count_nb_integers(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	nb_integers;

	i = 1;
	nb_integers = 0;
	while ((int)i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-'
				|| argv[i][j] == '+')
			{
				nb_integers++;
				j++;
				while (argv[i][j] != ' ' && argv[i][j] != '\0')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (nb_integers);
}

int	get_max(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	tmp = stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
