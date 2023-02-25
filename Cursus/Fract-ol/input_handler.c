/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:08 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/25 16:44:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_fract_name(char *fract_name)
{
	if (ft_strcmp(fract_name, "julia") && ft_strcmp(fract_name, "mandelbrot")
		&& ft_strcmp(fract_name, "burning_ship") && ft_strcmp(fract_name,
			"burning_ship_julia"))
		return (WRONG_FRACT_NAME);
	return (NO_ERROR);
}

static void	print_manual(char *error_message, t_fract *fract)
{
	ft_printf("#\n");
	ft_printf("#  ERROR : %s\n", error_message);
	ft_printf("#\n");
	ft_printf("###################### FRACT-OL Manuel ###########################\n");
	ft_printf("#                                                                #\n");
	ft_printf("#  available fractals :                                          #\n");
	ft_printf("#   | julia                                                      #\n");
	ft_printf("#   | mandelbrot                                                 #\n");
	ft_printf("#   | burning_ship                                               #\n");
	ft_printf("#   | burning_ship_julia                                         #\n");
	ft_printf("#                                                                #\n");
	ft_printf("##################################################################\n");
	exit_program(fract);
}

void	handle_input(int ac, char **cmd_input, t_fract *fract)
{
	if (ac < 2 || check_fract_name(cmd_input[1]) != NO_ERROR)
		print_manual(WRONG_NAME_MSSG, fract);
}
