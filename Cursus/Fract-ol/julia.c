/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/19 02:20:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_fract *fract)
{
    fract->vars->zoom = 0.7;
	fract->vars->max_iteration = 50;
	fract->vars->re_start = -2;
	fract->vars->re_end = 2;
	fract->vars->imag_start = -1.5;
	fract->vars->imag_end = 1.5;
	fract->vars->zoom_in = 0;
	fract->vars->move_x = 0;
	fract->vars->move_y = 0;
	fract->vars->zoom_in = 0;
	fract->vars->red = 9;
	fract->vars->green = 9;
	fract->vars->blue = 25;
	fract->vars->smoothing = 0;
    fract->vars->c.z_real = -0.7;
    fract->vars->c.z_imag = 0.27015;
    fract->vars->pause_julia = 0;
}

void iterate_julia(t_fract *fract)
{
    int iteration;
    
    t_complexe z,z_new,dz_new, dz;
    
    double tmp_real;
    
    z.z_imag = 0;
    dz.z_real = 0;
    dz.z_imag = 0;
    iteration = 1;
    z_new.z_real = coodinates_converter_x(fract->vars->x,fract);
    z_new.z_imag = coodinates_converter_y(fract->vars->y,fract);
    while (iteration < fract->vars->max_iteration)
    {
        dz.z_real = z_new.z_real;
        dz.z_imag = z_new.z_imag;
        z_new.z_real = dz.z_real * dz.z_real - dz.z_imag * dz.z_imag + fract->vars->c.z_real;
        z_new.z_imag = 2 * dz.z_real * dz.z_imag + fract->vars->c.z_imag;
        if (z_new.z_real * z_new.z_real + z_new.z_imag * z_new.z_imag > 4)
            break;
        iteration++;
    }
    set_pixel_color(fract, iteration, z_new);
}

int render_julia(t_fract *fract)
{
    fract->vars->x = 0;
    while (fract->vars->x < WIDTH)
    {
        fract->vars->y = 0;
        while (fract->vars->y < HIGHT)
        {
            iterate_julia(fract);
            mlx_put_pixel_img(fract);
            fract->vars->y++;
        }
        fract->vars->x++;
    }
    mlx_put_image_to_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr,
			fract->img_vars->img, 0, 0);
    return (0);
}




