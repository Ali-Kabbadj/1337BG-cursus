/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:08 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 11:32:35 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static int	check_fract_name(char *fract_name)
{
	if (ft_strcmp(fract_name, "julia") && ft_strcmp(fract_name, "mandelbrot")
		&& ft_strcmp(fract_name, "burning_ship") && ft_strcmp(fract_name,
			"burning_ship_julia") && ft_strcmp(fract_name, "custom_julia"))
		return (WRONG_FRACT_NAME);
	return (NO_ERROR);
}

static void	print_manual(char *error_message, t_fract *fract)
{
	ft_printf("####################################################\n");
	ft_printf("#                                                  #\n");
	ft_printf("#  ERROR : %s  #\n", error_message);
	ft_printf("#                                                  #\n");
	ft_printf("###################### FRACT-OL Manual #############\n");
	ft_printf("#                                                  #\n");
	ft_printf("#  usage : ./fractol <name>                        #\n");
	ft_printf("#                                                  #\n");
	ft_printf("#  available fractals names :                      #\n");
	ft_printf("#   | julia                                        #\n");
	ft_printf("#   | mandelbrot                                   #\n");
	ft_printf("#   | burning_ship                                 #\n");
	ft_printf("#   | burning_ship_julia                           #\n");
	ft_printf("#   | custom_julia                                 #\n");
	ft_printf("#                                                  #\n");
	ft_printf("####################################################\n");
	exit_program(fract);
}

void	handle_input(int ac, char **cmd_input, t_fract *fract)
{
	if (ac < 2 || check_fract_name(cmd_input[1]) == WRONG_FRACT_NAME)
		print_manual(WRONG_NAME_MSSG, fract);
}
