/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:46:59 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 14:56:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burning_ship_julia_formula(t_complexe *z, t_complexe c)
{
	double	temp;

	temp = z->real;
	z->real = fabs(z->real * z->real) - fabs(z->imag * z->imag) + c.real;
	z->imag = 2 * fabs(z->imag) * fabs(temp)  + c.imag;
}

static void	iteration_burning_ship_julia_on_one_point(t_fract *fract)
{
	fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
	fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
	while (fract->vars.iterations < fract->vars.max_iteration
		&& absolute_value(fract->vars.z) <= 40)
	{
		burning_ship_julia_formula(&fract->vars.z, fract->vars.c);
		fract->vars.iterations++;
	}
	set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
	fract->vars.iterations = 0;
	mlx_put_pixel_img(fract);
}

void	render_burning_ship_julia(t_fract *fract)
{
	fract->vars.win_axis.x = 0;
	while (fract->vars.win_axis.x < WIDTH)
	{
		fract->vars.win_axis.y = 0;
		while (fract->vars.win_axis.y < HIGHT)
		{
			iteration_burning_ship_julia_on_one_point(fract);
			fract->vars.win_axis.y++;
		}
		fract->vars.win_axis.x++;
	}
	mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
			fract->img_vars.img, 0, 0);
	return (0);
}
