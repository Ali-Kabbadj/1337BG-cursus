/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 09:33:21 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_fract(t_fract *fract)
{
    if (fract->vars.id == 1)
        render_julia(fract);
    if (fract->vars.id == 2)
	    render_mandelbrot(fract);
}

void mlx_put_pixel_img(t_fract *fract)
{
    char *dst;

    dst = fract->img_vars.addr + (fract->vars.win_axis.y * fract->img_vars.line_lenght + fract->vars.win_axis.x * (fract->img_vars.bpp / 8));
    *(unsigned int *)dst = fract->vars.colors.color;
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
