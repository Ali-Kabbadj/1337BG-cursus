/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:51:14 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 16:08:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

double	coodinates_converter_x(double x, t_fract *fract)
{
	return (x * (fract->vars.complex_axis.x_end
			- fract->vars.complex_axis.x_start) / IMAGE_WIDTH
		+ fract->vars.complex_axis.x_start + fract->vars.move_x);
}

double	coodinates_converter_y(double y, t_fract *fract)
{
	return (fract->vars.complex_axis.y_end - (y
			* (fract->vars.complex_axis.y_end
				- fract->vars.complex_axis.y_start) / IMAGE_HIGHT
			+ fract->vars.move_y));
}

void	ft_move_color(t_fract *fract, int key)
{
	if (key == K_R)
		fract->vars.colors.red += 1;
	else if (key == K_G)
		fract->vars.colors.green += 1;
	else if (key == K_B)
		fract->vars.colors.blue += 1;
	else if (key == K_A)
		fract->vars.colors.transparency += 1;
	else if (key == K_S)
		fract->vars.colors.red -= 1;
	else if (key == K_D)
		fract->vars.colors.green -= 1;
	else if (key == K_F)
		fract->vars.colors.blue -= 1;
	else if (key == K_Q)
		fract->vars.colors.transparency -= 1;
}

static void	decide_color(t_fract *fract)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	transparency;
	double			smooth_color;

	red = 0;
	green = 0;
	blue = 0;
	transparency = 0;
	if (fract->vars.switch_color_formula == 0)
		smooth_color = fract->vars.iterations + (log(log(200))
				- (log(log(sqrt(absolute_value(fract->vars.z))))) / log(2));
	else
		smooth_color = fract->vars.iterations + (log(log(200))
				- (log(log(sqrt(absolute_value(fract->vars.z)))))
				/ log(fract->vars.e_z));
	transparency = fract->vars.colors.transparency * smooth_color;
	red = fract->vars.colors.red * smooth_color;
	green = fract->vars.colors.green * smooth_color;
	blue = fract->vars.colors.blue * smooth_color;
	fract->vars.colors.color = (transparency << 24)
		| (red << 16) | (green << 8) | blue;
}

void	set_pixel_color(t_fract *fract)
{
	if (fract->vars.iterations == fract->vars.max_iteration)
	{
		fract->vars.colors.color = BLACK;
		return ;
	}
	decide_color(fract);
}
