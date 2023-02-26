/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:51:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 14:49:25 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	default_shared(t_fract *fract)
{
	fract->vars.zoom = 0.9;
	fract->vars.max_iteration = 30;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.colors.red = 248;
	fract->vars.colors.green = 80;
	fract->vars.colors.blue = 35;
	fract->vars.iterations = 0;
	fract->vars.move = 0.09;
	fract->vars.color_turn = 0;
	fract->vars.pause_color_cycle = 0;
	fract->vars.colors.transparency = 50;
}

static void	default_julia(t_fract *fract)
{
	fract->vars.complex_axis.x_start = JULIA_X_START;
	fract->vars.complex_axis.x_end = JULIA_X_END;
	fract->vars.complex_axis.y_start = JULIA_Y_START;
	fract->vars.complex_axis.y_end = JULIA_Y_END;
	fract->vars.c.real = 0.37;
	fract->vars.c.imag = 0.1;
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

static void	default_burning_ship_julia(t_fract *fract)
{
	fract->vars.complex_axis.x_start = BURNING_SHIP_JULIA_X_START;
	fract->vars.complex_axis.x_end = BURNING_SHIP_JULIA_X_END;
	fract->vars.complex_axis.y_start = BURNING_SHIP_JULIA_Y_START;
	fract->vars.complex_axis.y_end = BURNING_SHIP_JULIA_Y_END;
	fract->vars.c.real = -0.5;
	fract->vars.c.imag = 0.15;
	fract->vars.pause_julia = 0;
}

void	default_fract(t_fract *fract)
{
	default_shared(fract);
	if (fract->vars.id == JULIA_ID)
		default_julia(fract);
	else if (fract->vars.id == MANDELBROT_ID)
		default_mandelbrot(fract);
	else if (fract->vars.id == BURNING_SHIP_ID)
		default_burning_ship(fract);
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
		default_burning_ship_julia(fract);
}