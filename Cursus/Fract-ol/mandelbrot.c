/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 10:00:22 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fract *fract)
{
	fract->vars.zoom = 0.9;
	fract->vars.max_iteration = 50;
	fract->vars.complex_axis.x_start = -2;
	fract->vars.complex_axis.x_end = 2;
	fract->vars.complex_axis.y_start = -2;
	fract->vars.complex_axis.y_end = 2;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.colors.red = 9;
	fract->vars.colors.green = 9;
	fract->vars.colors.blue = 25;
	fract->vars.iterations = 0;
	fract->vars.move = 0.09;
}

static void iterate_mandelbrot_on_one_point(t_fract *fract)
{
	fract->vars.z.real = 0;
	fract->vars.z.imag = 0;
	fract->vars.c.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
	fract->vars.c.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
	while (fract->vars.iterations < fract->vars.max_iteration && sqrt_root_modulus(fract->vars.z) <= 4)
	{
		mandelbrot_julia_formula(&fract->vars.z, fract->vars.c);
		fract->vars.iterations++;
	}
	set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
	fract->vars.iterations = 0;
	mlx_put_pixel_img(fract);
}

void	*iterate_mandelbrot(void *param)
{
	t_fract *fract;
	t_fract *fract_copy;
	int i;
	int j;

	fract = (t_fract *)param;
	fract_copy = malloc(sizeof(t_fract));
	*fract_copy = *fract;
	i =fract->vars.win_axis.x;
	while (i < fract->vars.win_axis.x + (WIDTH / THREADS))
	{
		j = 0;
		while (j < HIGHT)
		{
			fract_copy->vars.win_axis.x = i;
			fract_copy->vars.win_axis.y = j;
			iterate_mandelbrot_on_one_point(fract_copy);
			j++;
		}
		i++;
	}
	free(fract_copy);
	return (0);
}

int render_mandelbrot(t_fract *fract)
{
	iterate_multithreading(fract);
	return (0);
}