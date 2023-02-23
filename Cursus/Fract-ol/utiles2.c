/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:51:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 00:26:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void reset_julia(t_fract *fract)
{
    fract->vars.move_x = 0;
    fract->vars.move_y = 0;
    fract->vars.move = 0.09;
    fract->vars.complex_axis.x_start = JULIA_X_START;
    fract->vars.complex_axis.x_end = JULIA_X_END;
    fract->vars.complex_axis.y_start = JULIA_Y_START;
    fract->vars.complex_axis.y_end = JULIA_Y_END;
    fract->vars.max_iteration = 50;
}

void reset_mandelbrot(t_fract *fract)
{
    fract->vars.move_x = 0;
    fract->vars.move_y = 0;
    fract->vars.move = 0.09;
    fract->vars.complex_axis.x_start = MANDELBROT_X_START;
    fract->vars.complex_axis.x_end = MANDELBROT_X_END;
    fract->vars.complex_axis.y_start = MANDELBROT_Y_START;
    fract->vars.complex_axis.y_end = MANDELBROT_Y_END;
}