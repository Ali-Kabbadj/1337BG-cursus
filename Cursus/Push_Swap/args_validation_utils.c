/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:30:15 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/11 00:00:10 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	valid_char(char arg, size_t *force_check_int, size_t *found_int_prev)
{
	if (ft_isdigit(arg))
		*found_int_prev = TRUE;
	else if (arg == '-' || arg == '+')
		*force_check_int = TRUE;
	else if (arg != ' ')
		exit_program(ARG_INVALID_MSSG, ARG_INVALID_ID);
}

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
				integers[j] = ft_atoi(&argv[i][k]);
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
	j = 0;
	nb_integers = 0;
	while ((int)i < argc)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-'
				|| argv[i][j] == '+')
			{
				nb_integers++;
				while ((ft_isdigit(argv[i][j]) || argv[i][j] == '-'
						|| argv[i][j] == '+'))
					j++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (nb_integers);
}
