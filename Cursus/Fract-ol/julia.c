/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/22 11:48:09 by akabbadj         ###   ########.fr       */
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
	fract->vars.zoom_in = 0;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.zoom_in = 0;
	fract->vars.colors.red = 11;
	fract->vars.colors.green = 12;
	fract->vars.colors.blue = 27;
    fract->vars.pause_julia = 0;
    fract->vars.iterations = 0;
    fract->vars.move = 0.09;
}

static void julia_formula(t_complexe *z, t_complexe c)
{
    long double tmp_z_re;
    
    tmp_z_re = z->real;
    z->real = z->real * z->real - z->imag * z->imag + c.real;
    z->imag = 2 * tmp_z_re * z->imag + c.imag;
}

void iteration_julia_on_one_point(t_fract *fract)
{
    
    fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
    fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
    while (fract->vars.iterations < fract->vars.max_iteration && sqrt_root_modulus(fract->vars.z) <= 4)
    {
        julia_formula(&fract->vars.z, fract->vars.c);
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
    return (0);
}

void *iterate_multithreading(t_fract *fract)
{
    pthread_t thread[THREADS];
    t_fract fract_copy[THREADS];
    int i;
    
    i = 0;
    while (i < THREADS)
    {
        fract_copy[i] = *fract;
        fract_copy[i].vars.win_axis.x = i * (WIDTH / THREADS);
        if (fract->vars.id == JULIA_ID)
            pthread_create(&thread[i], NULL, iterate_julia, &fract_copy[i]);
        else if (fract->vars.id == MANDELBROT_ID)
            pthread_create(&thread[i], NULL, iterate_mandelbrot, &fract_copy[i]);
        i++;
    }
    i = 0;
    while (i < THREADS)
    {
        pthread_join(thread[i], NULL);
        i++;
    }
    mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
            fract->img_vars.img, 0, 0);
    return (0);  
}



int render_julia(t_fract *fract)
{
    iterate_multithreading(fract);
    return (0);
}

