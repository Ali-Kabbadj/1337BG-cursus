/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 10:00:08 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_fract *fract)
{
    fract->vars.zoom = 0.9;
	fract->vars.max_iteration = 50;
	fract->vars.complex_axis.x_start = -2;
	fract->vars.complex_axis.x_end = 2;
	fract->vars.complex_axis.y_start = -1.5;
	fract->vars.complex_axis.y_end = 1.5;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.colors.red = 11;
	fract->vars.colors.green = 12;
	fract->vars.colors.blue = 27;
    fract->vars.pause_julia = 0;
    fract->vars.iterations = 0;
    fract->vars.move = 0.09;
    fract->vars.c.real = -0.162;
    fract->vars.c.imag = 1.04;
}

static void iteration_julia_on_one_point(t_fract *fract)
{
    fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
    fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
    while (fract->vars.iterations < fract->vars.max_iteration && sqrt_root_modulus(fract->vars.z) <= 4)
    {
        mandelbrot_julia_formula(&fract->vars.z, fract->vars.c);
        fract->vars.iterations++;
    }
    set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
    fract->vars.iterations = 0;
    mlx_put_pixel_img(fract);
}

void *iterate_julia(void *param)
{
    t_fract *fract;
    t_fract *fract_copy;
    int i;
    int j;
    
    fract = (t_fract *)param;
    fract_copy = malloc(sizeof(t_fract));
    *fract_copy = *fract;
    i = fract->vars.win_axis.x;
    while (i < fract->vars.win_axis.x + (WIDTH / THREADS))
    {
        j = 0;
        while (j < HIGHT)
        {
            fract_copy->vars.win_axis.x = i;
            fract_copy->vars.win_axis.y = j;
            iteration_julia_on_one_point(fract_copy);
            j++;
        }
        i++;
    }
    free(fract_copy);
    return (0);
}

int render_julia(t_fract *fract)
{
    iterate_multithreading(fract);
    return (0);
}

