/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:46:59 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 15:54:14 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"
#include "stdio.h"

static void	set_initial_values(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID
		|| fract->vars.id == CUSTOM_JULIA_ID)
	{
		fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x,
				fract);
		fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y,
				fract);
	}
	else if (fract->vars.id == MANDELBROT_ID
		|| fract->vars.id == BURNING_SHIP_ID)
	{
		fract->vars.z.real = 0;
		fract->vars.z.imag = 0;
		fract->vars.c.real = coodinates_converter_x(fract->vars.win_axis.x,
				fract);
		fract->vars.c.imag = coodinates_converter_y(fract->vars.win_axis.y,
				fract);
	}
}

void	iteration(t_fract *fract)
{
	fract->vars.iterations = 0;
	set_initial_values(fract);
	while (fract->vars.iterations < fract->vars.max_iteration
		&& absolute_value(fract->vars.z) <= 400)
	{
		if (fract->vars.id == JULIA_ID || fract->vars.id == MANDELBROT_ID)
			mandelbrot_julia_formula(&fract->vars.z, fract->vars.c);
		else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
			burning_ship_julia_formula(&fract->vars.z, fract->vars.c);
		else if (fract->vars.id == CUSTOM_JULIA_ID)
			custom_julia_formula(&fract->vars.z, fract->vars.c);
		else if (fract->vars.id == BURNING_SHIP_ID)
			burning_ship_formula(&fract->vars.z, fract->vars.c);
		fract->vars.iterations++;
		if (fract->vars.switch_color_formula == 1)
			fract->vars.e_z += 1 / pow(2.718,
					sqrt(absolute_value(fract->vars.z)));
	}
	set_pixel_color(fract);
	mlx_put_pixel_img(fract);
}
