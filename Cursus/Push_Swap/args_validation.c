/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:21:47 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/11 00:19:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	validate_no_duplicates(int argc, char **argv)
{
	int		*integers;
	size_t	i;
	size_t	j;
	size_t	nb_count;

	nb_count = count_nb_integers(argc, argv);
	integers = (int *)malloc(sizeof(int) * (((int)nb_count + 1)));
	if (integers == NULL)
		exit_program(MALLOC_ERROR_MSSG, MALLOC_ERROR_ID);
	to_int_array(argv, integers);
	i = 0;
	j = 0;
	while (i < nb_count)
	{
		while (j < nb_count)
		{
			if (integers[i] == integers[j] && i != j)
				exit_program(DUPLICATE_DIGIT_MSSG, DUPLICATE_DIGIT_ID);
			j++;
		}
		j = 0;
		i++;
	}
	free(integers);
}

void	validate_format(char *arg)
{
	size_t	slen;
	size_t	i;
	size_t	found_int_prev;
	size_t	force_check_int;

	slen = ft_strlen(arg);
	i = 0;
	found_int_prev = FALSE;
	force_check_int = FALSE;
	while (i < slen)
	{
		if (ft_isdigit(arg[i]) == FALSE && arg[i] != ' '
			&& (found_int_prev == TRUE || i == slen - 1))
			exit_program(ARG_INVALID_MSSG, ARG_INVALID_ID);
		if (ft_isdigit(arg[i]) == FALSE && force_check_int == TRUE)
			exit_program(ARG_INVALID_MSSG, ARG_INVALID_ID);
		valid_char(arg[i], &force_check_int, &found_int_prev);
		if (arg[i] == ' ' || found_int_prev == TRUE)
		{
			force_check_int = FALSE;
			found_int_prev = FALSE;
		}
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		validate_format(argv[i]);
		i++;
	}
	validate_no_duplicates(argc, argv);
}
