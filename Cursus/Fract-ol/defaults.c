/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:51:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 08:35:03 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static void	default_julias(t_fract *fract)
{
	fract->vars.complex_axis.x_start = JULIA_X_START;
	fract->vars.complex_axis.x_end = JULIA_X_END;
	fract->vars.complex_axis.y_start = JULIA_Y_START;
	fract->vars.complex_axis.y_end = JULIA_Y_END;
	if (fract->vars.id == JULIA_ID)
	{
		fract->vars.c.real = 0.37;
		fract->vars.c.imag = 0.1;
	}
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
	{
		fract->vars.c.real = -1.7;
		fract->vars.c.imag = -0.05;
	}
	fract->vars.pause_julia = 0;
}

static void	default_mandelbrot(t_fract *fract)
{
	fract->vars.complex_axis.x_start = MANDELBROT_X_START;
	fract->vars.complex_axis.x_end = MANDELBROT_X_END;
	fract->vars.complex_axis.y_start = MANDELBROT_Y_START;
	fract->vars.complex_axis.y_end = MANDELBROT_Y_END;
}

static void	default_burning_ship(t_fract *fract)
{
	fract->vars.complex_axis.x_start = BURNING_SHIP_X_START;
	fract->vars.complex_axis.x_end = BURNING_SHIP_X_END;
	fract->vars.complex_axis.y_start = BURNING_SHIP_Y_START;
	fract->vars.complex_axis.y_end = BURNING_SHIP_Y_END;
}

static void	default_custom_julia(t_fract *fract)
{
	fract->vars.complex_axis.x_start = CUSTOM_JULIA_X_START;
	fract->vars.complex_axis.x_end = CUSTOM_JULIA_X_END;
	fract->vars.complex_axis.y_start = CUSTOM_JULIA_Y_START;
	fract->vars.complex_axis.y_end = CUSTOM_JULIA_Y_END;
	fract->vars.c.real = -1.7;
	fract->vars.c.imag = -0.05;
	fract->vars.pause_julia = 0;
}

void	init_vars(t_fract *fract)
{
	default_shared(fract);
	if (fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID)
		default_julias(fract);
	else if (fract->vars.id == MANDELBROT_ID)
		default_mandelbrot(fract);
	else if (fract->vars.id == BURNING_SHIP_ID)
		default_burning_ship(fract);
	else if (fract->vars.id == CUSTOM_JULIA_ID)
		default_custom_julia(fract);
}
