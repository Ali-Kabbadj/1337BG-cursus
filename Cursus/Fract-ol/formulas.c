/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:08:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 11:22:11 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

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
	z->real = z->real * z->real - z->imag * z->imag + c.real;
	z->imag = 2 * fabs(z->imag * temp) + c.imag;
}

void	custom_julia_formula(t_complexe *z, t_complexe c)
{
	double	temp;

	temp = z->real;
	z->real = fabs(z->real * z->real - z->imag * z->imag) + c.real;
	z->imag = 2 * fabs(z->imag * temp) + c.imag;
}

void	burning_ship_formula(t_complexe *z, t_complexe c)
{
	double	temp;

	temp = z->real;
	z->real = z->real * z->real - z->imag * z->imag + c.real;
	z->imag = 2 * fabs(z->imag * temp) + c.imag;
}

double	absolute_value(t_complexe z)
{
	return (z.real * z.real + z.imag * z.imag);
}
