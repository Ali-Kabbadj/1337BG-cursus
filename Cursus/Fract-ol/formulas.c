/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:08:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 14:56:46 by akabbadj         ###   ########.fr       */
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
	z->imag = 2 * fabs(z->imag) * fabs(temp)  + c.imag;
}

double	absolute_value(t_complexe z)
{
	return (z.real * z.real + z.imag * z.imag);
}