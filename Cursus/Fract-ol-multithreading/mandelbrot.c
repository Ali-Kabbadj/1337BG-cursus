/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 16:46:28 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iterate_mandelbrot_on_one_point(t_fract *fract)
{
	fract->vars.z.real = 0;
	fract->vars.z.imag = 0;
	fract->vars.c.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
	fract->vars.c.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
	while (fract->vars.iterations < fract->vars.max_iteration
		&& absolute_value(fract->vars.z) <= 400)
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


void render_mandelbrot(t_fract *fract)
{
	iterate_multithreading(fract);
}