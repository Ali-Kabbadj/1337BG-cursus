/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:51:14 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 16:47:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	coodinates_converter_x(double x, t_fract *fract)
{
	return (x * (fract->vars.complex_axis.x_end
			- fract->vars.complex_axis.x_start) / WIDTH
		+ fract->vars.complex_axis.x_start + fract->vars.move_x);
}

double	coodinates_converter_y(double y, t_fract *fract)
{
	return (fract->vars.complex_axis.y_end - (y
			* (fract->vars.complex_axis.y_end
				- fract->vars.complex_axis.y_start) / HIGHT
			+ fract->vars.move_y));
}
void ft_move_color(t_fract *fract, int key)
{
	if (key == K_R)
		fract->vars.colors.red += 1;
	else if (key == K_G)
		fract->vars.colors.green += 1;
	else if (key == K_B)
		fract->vars.colors.blue += 1;
	else if (key == K_T)
		fract->vars.colors.transparency += 1;
}

void	set_pixel_color(t_fract *fract, int iterations, t_complexe z)
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char transparency;
	double smooth_color;

	red = 0;
	green = 0;
	blue = 0;
	transparency = 0;
	if (iterations == fract->vars.max_iteration)
	{
		fract->vars.colors.color = 0x000000;
		return ;
	}
	smooth_color = iterations + (log(log(200))
			- (log(log(sqrt(absolute_value(z))))) / log(2));
	transparency = fract->vars.colors.transparency * smooth_color;
	red = fract->vars.colors.red * smooth_color;
	green = fract->vars.colors.green * smooth_color;
	blue = fract->vars.colors.blue * smooth_color;
	fract->vars.colors.color = transparency << 24 | red | green << 8 | blue << 16;
}