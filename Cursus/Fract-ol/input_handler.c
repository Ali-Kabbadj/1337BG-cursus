/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:08 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/22 22:14:49 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// ./fractal <fractal-name> 
// if julia
// ./fractal julia && --const real=value imag=value --colors red= green= blue= && --max_iterations value 

// typedef struct  s_cmd_input
// {
//     /* data */
// };  t_cmd_input;



//needs to be moved to another file !
// static char *str_toupper(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         str[i] = (unsigned char)ft_toupper(str[i]);
//         i++;
//     }
//     return (str);
// }


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
    ft_printf("#  available shared flags :                                      #\n");
    ft_printf("#     --colors <name>=<value>  options      : (red,greed,blue)   #\n");
    ft_printf("#                              value range  : (0,255)            #\n");
    ft_printf("#                                                                #\n");
    ft_printf("#    --max_iterations <value>                                    #\n");
    ft_printf("#                                                                #\n");
    ft_printf("#  specific flags                                                #\n");
    ft_printf("#   julia                                                        #\n");
    ft_printf("#     --c read=<value>  imag=<value>                             #\n");
    ft_printf("#                                                                #\n");
    ft_printf("##################################################################\n");
    exit_program(fract);
}

static void handle_fractal_name(char **cmd_input, t_fract *fract)
{
    if (check_fract_name(cmd_input[1]) != NO_ERROR)
        print_manual(WRONG_NAME_MSSG,fract);
    
}

int handle_input(int ac , char **cmd_input, t_fract *fract)
{   
    int res;

    res = 0;
    if (ac < 2)
        return (NO_ARGS_ERROR);
    handle_fractal_name(cmd_input, fract);
    handel_args(ac,cmd_input);
    // if (fract->vars.id == JULIA_ID)
    //     res = handle_julia_input();
    // else if (fract->vars.id == MANDELBROT_ID)
    //     res = handel_mandelbrot_input();
    return (res);   
}

static void set_color(char *color)
{
    if (!ft_strncmp(color , "red", 3))
        printf("red\n");
    else if(!ft_strncmp(color , "green" ,5))
        printf("green\n");
    else if (!ft_strncmp(color, "blue", 4))
        printf("blue\n");
}

static void handel_color_input(int ac, char **cmd_input, int idx)
{
    int i;

    i = idx;
    while (!ft_strncmp(cmd_input[i] , "red", 3) || !ft_strncmp(cmd_input[i] , "green" ,5) || !ft_strncmp(cmd_input[i] , "blue", 4) || i < ac)
    {
        set_color(cmd_input[i]);
        i++;
    }
    
}

void handel_args(int ac, char **cmd_input)
{
    int i;

    i = 2;
    while (i <= ac)
    {
        if (!ft_strcmp(cmd_input[i], "--colors"))
        {
            i++;
            handel_color_input(ac , cmd_input, i);
        }
        i++;
    }
    
}

