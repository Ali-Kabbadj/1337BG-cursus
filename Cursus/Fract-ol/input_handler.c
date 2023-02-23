/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:08 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 08:07:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int check_fract_name(char *fract_name)
{
    if (ft_strcmp(fract_name, "julia") && ft_strcmp(fract_name, "mandelbrot"))
        return (WRONG_FRACT_NAME);
    return(NO_ERROR);
}

static void print_manual(char *error_message, t_fract *fract)
{
    ft_printf("#\n");
    ft_printf("#  ERROR : %s\n",error_message);
    ft_printf("#\n");
    ft_printf("###################### FRACT-OL Manuel ###########################\n");
    ft_printf("#                                                                #\n");
    ft_printf("#  available fractals :                                          #\n");
    ft_printf("#   | Julia                                                      #\n");
    ft_printf("#   | Mandelbrot                                                 #\n");
    ft_printf("#                                                                #\n");
    ft_printf("##################################################################\n");
    exit_program(fract);
}

void handle_input(int ac ,char **cmd_input, t_fract *fract)
{
    if (ac < 2 || check_fract_name(cmd_input[1]) != NO_ERROR)
	    print_manual(WRONG_NAME_MSSG,fract);
}

