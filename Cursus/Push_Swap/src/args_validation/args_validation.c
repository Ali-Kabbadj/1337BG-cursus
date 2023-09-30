/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:21:47 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 11:49:10 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/args_validation/args_validation.h"
#include "../../includes/global_macros.h"

void	validate_no_duplicates(int argc, char **argv)
{
	int		*integers;
	size_t	i;
	size_t	j;
	size_t	nb_count;

	nb_count = count_nb_integers(argc, argv);
	integers = (int *)malloc(sizeof(int) * (((int)nb_count)));
	if (!integers)
		exit_program(NULL, NULL, 2);
	to_int_array(argv, integers);
	i = 0;
	j = 0;
	while (i < nb_count)
	{
		while (j < nb_count)
		{
			if (integers && integers[i] == integers[j] && i != j)
				exit_program(NULL, NULL, 2);
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
			exit_program(NULL, NULL, 2);
		if (ft_isdigit(arg[i]) == FALSE && force_check_int == TRUE)
			exit_program(NULL, NULL, 2);
		valid_char(arg[i], &force_check_int, &found_int_prev);
		if (arg[i] == ' ')
			force_check_int = FALSE;
		else if (arg[i] == '-' || arg[i] == '+')
			force_check_int = TRUE;
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2 || count_nb_integers(argc, argv) < 2)
		exit_program(NULL, NULL, 2);
	while (i <= argc)
	{
		validate_format(argv[i]);
		i++;
	}
	validate_no_duplicates(argc, argv);
}
