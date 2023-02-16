/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/16 22:22:58 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void one_time_init(t_fract *fract)
{
    fract->vars->zoom = 1;
    fract->vars->max_iteration = 50;
    fract->vars->re_start = -2;
    fract->vars->re_end = 0.5;
    fract->vars->imag_start = -1;
    fract->vars->imag_end = 1;
}

void init_mandelbrot(t_fract *fract)
{
    fract->vars->z.z_real = 0;
    fract->vars->z.z_imag = 0;
}

float coodinates_converter_x(float x , t_fract *fract)
{
    return((x  - WIDTH / 2) / (0.5 * fract->vars->zoom * WIDTH) + fract->vars->move_x);
}

float coodinates_converter_y(float y, t_fract *fract)
{
    return((y - HIGHT / 2) / (0.5 * fract->vars->zoom * HIGHT) + fract->vars->move_y);
}

void iterate_mandelbrot(t_fract *fract)
{
    int i;
    float tmp_re;
    float tmp_img;

    i = 0;
    tmp_re = 0; 
    tmp_img = 0; 
    if (!fract->vars->move_x)
        fract->vars->move_x = -0.5;
    if (!fract->vars->move_y)
        fract->vars->move_y = 0;
    fract->vars->x_re = coodinates_converter_x(fract->vars->x, fract);
    fract->vars->x_img = coodinates_converter_y(fract->vars->y, fract);
    // fract->vars->x_re = (fract->vars->x  - WIDTH / 2) / (0.5 * fract->vars->zoom * WIDTH) + fract->vars->move_x;
    // fract->vars->x_img = (fract->vars->y - HIGHT / 2) / (0.5 * fract->vars->zoom * HIGHT) + fract->vars->move_y;
    // fract->vars->x_re = (fract->vars->x  * (fract->vars->re_end - fract->vars->re_start)) / WIDTH + fract->vars->re_start + fract->vars->move_x;
    // fract->vars->x_img = fract->vars->imag_end - (fract->vars->y * (fract->vars->imag_end - fract->vars->imag_end) / HIGHT) + fract->vars->move_y;
    while (i < fract->vars->max_iteration)
    {
        tmp_re = fract->vars->z.z_real;
        tmp_img = fract->vars->z.z_imag;   
        
        fract->vars->z.z_real = tmp_re * tmp_re - tmp_img * tmp_img + fract->vars->x_re;
        fract->vars->z.z_imag = 2 * tmp_re * tmp_img + fract->vars->x_img;
        
        if (fract->vars->z.z_real * fract->vars->z.z_real + fract->vars->z.z_imag * fract->vars->z.z_imag > 4)
            break;
        i++;
    }
    fract->vars->iterations = i;
    if (fract->vars->iterations == 50)
        fract->vars->color = 0x000000;
    else
        fract->vars->color = 0xFFFFFF;
}

int render_mandelbrot(t_fract *fract)
{
    fract->vars->x = 0;
    while (fract->vars->x < WIDTH)
    {
        fract->vars->y = 0;
        while (fract->vars->y < HIGHT)
        {
            init_mandelbrot(fract);
            iterate_mandelbrot(fract);
            mlx_put_pixel_img(fract);
            fract->vars->y++;
        }
        fract->vars->x++;
    }
    mlx_put_image_to_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr, fract->img_vars->img, 0, 0);
    return (0);
}
