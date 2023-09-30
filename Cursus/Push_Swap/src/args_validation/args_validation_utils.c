/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:30:15 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 13:08:41 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/args_validation/args_validation.h"
#include "../../includes/global_macros.h"
#include <limits.h>

int	set_sign(unsigned char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

void	free_and_exit(char *str, int *integers)
{
	free((void *)str);
	free(integers);
	exit_program(NULL, NULL, 2);
}

int	ft_atoi_no_overflow(const char *str, int *integers)
{
	int	i;
	int	sign;
	int	res;
	int	digit;

	i = 0;
	sign = 1;
	res = 0;
	digit = 0;
	if (!str[0])
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = set_sign(str[i++]);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		if ((sign == 1 && res > INT_MAX / 10) || (sign == -1 && res < INT_MIN
				/ 10))
			free_and_exit((char *)str, integers);
		res = res * 10 + digit;
	}
	return (res * sign);
}

void	valid_char(char arg, size_t *force_check_int, size_t *found_int_prev)
{
	if (ft_isdigit(arg))
		*found_int_prev = TRUE;
	else if (arg == '-' || arg == '+')
		*force_check_int = TRUE;
	else if (arg != ' ')
		exit_program(NULL, NULL, 2);
}
