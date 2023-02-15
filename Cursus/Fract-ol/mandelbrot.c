/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/15 19:11:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void init_mandelbrot(t_fract *fract)
{
    fract->vars->move_x = -2;
    fract->vars->move_y = -1.5;
    fract->vars->max_iteration = 50;
    fract->vars->iterations = 0;
    fract->vars->z.z_real = 0;
    fract->vars->z.z_imag = 0;
    fract->vars->c.z_real = 0.8;
    fract->vars->c.z_imag = 1;
    fract->vars->re_start = -2;
    fract->vars->re_end = 2;
    fract->vars->imag_start = -2;
    fract->vars->imag_end = 2;
}

void iterate_mandelbrot(t_fract *fract)
{
    int i;

    i = 0;
    t_complexe z_tmp;
    while (i <= fract->vars->max_iteration)
    {
        z_tmp.z_real = fract->vars->z.z_real;
        z_tmp.z_imag = fract->vars->z.z_imag;
        
        fract->vars->z.z_real = fract->vars->z.z_real * fract->vars->z.z_real - fract->vars->z.z_imag * fract->vars->z.z_imag;
        fract->vars->z.z_imag = z_tmp.z_real * fract->vars->z.z_imag + fract->vars->z.z_imag * z_tmp.z_real;
        
        fract->vars->z.z_real = fract->vars->z.z_real + fract->vars->c.z_real;
        fract->vars->z.z_imag = fract->vars->z.z_imag + fract->vars->c.z_imag;
         //printf("%f\n", fract->vars->z.z_real);
        if (fract->vars->z.z_real * fract->vars->z.z_real + fract->vars->z.z_imag * fract->vars->z.z_imag >= 4 )
            break;
        i++;
    }
    fract->vars->iterations = i;
    // printf("%f - %f", z_tmp.z_real, z_tmp.z_imag);
    // printf("------");
}

void render_mandelbrot(t_fract *fract)
{
    init_mandelbrot(fract);
    fract->vars->x = 0;
    while (fract->vars->x < WIDTH)
    {
        fract->vars->y = 0;
        while (fract->vars->y < HIGHT)
        {
            fract->vars->z.z_real = (fract->vars->x *(fract->vars->re_end - fract->vars->re_end))/WIDTH + fract->vars->re_start;
            fract->vars->z.z_imag = (fract->vars->y *(fract->vars->imag_end - fract->vars->imag_start))/HIGHT;
            fract->vars->re_start;
            iterate_mandelbrot(fract);
            if (fract->vars->iterations < 50)
                fract->vars->color = 0xFFFFFF;
            else
                fract->vars->color = 0x000000;
            mlx_put_pixel_img(fract);
            fract->vars->y++;
        }
        fract->vars->x++;
    }
}
