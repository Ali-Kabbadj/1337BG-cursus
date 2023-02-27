/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:08:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 21:31:01 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_julia_formula(t_complexe *z, t_complexe c)
{
	double	tmp_z_re;

	tmp_z_re = z->real;
	z->real = z->real * z->real - z->imag * z->imag + c.real;
	z->imag = 2 * tmp_z_re * z->imag + c.imag;
}

void	burning_ship_julia_formula(t_complexe *z, t_complexe c)
{
	double	temp;

	temp = z->real;
	z->real = fabs(z->real * z->real) - fabs(z->imag * z->imag) + c.real;
	z->imag = 2 * fabs(z->imag * temp)  + c.imag;
}

void	custom_julia_formula(t_complexe *z, t_complexe c)
{
	double	temp;

	temp = z->real;
	z->real = fabs(z->real * z->real - z->imag * z->imag) + c.real;
	z->imag = 2 * fabs(z->imag * temp)  + c.imag;
}

void burning_ship_formula(t_complexe *z , t_fract *fract)
{
	double	temp;

	temp = z->real;
	z->real = z->real * z->real - z->imag * z->imag - coodinates_converter_x(fract->vars.win_axis.x, fract);
	z->imag = fabs(2 * z->imag * temp) - coodinates_converter_y(fract->vars.win_axis.y, fract);
}

double	absolute_value(t_complexe z)
{
	return (z.real * z.real + z.imag * z.imag);
}