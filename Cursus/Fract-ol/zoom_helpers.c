/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:17:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 17:31:18 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

void	cal_local_zoom(t_fract *fract,
		double mouse_x, double mouse_y)
{
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;

	x_start = fract->vars.complex_axis.x_start;
	x_end = fract->vars.complex_axis.x_end;
	y_start = fract->vars.complex_axis.y_start;
	y_end = fract->vars.complex_axis.y_end;
	fract->vars.complex_axis.x_start = mouse_x + fract->vars.zoom * (x_start
			- mouse_x);
	fract->vars.complex_axis.x_end = mouse_x + fract->vars.zoom * (x_end
			- mouse_x);
	fract->vars.complex_axis.y_start = mouse_y + fract->vars.zoom * (y_start
			- mouse_y);
	fract->vars.complex_axis.y_end = mouse_y + fract->vars.zoom * (y_end
			- mouse_y);
	fract->vars.move *= fract->vars.zoom;
}

void	cal_centered_zoom(t_fract *fract)
{
	fract->vars.complex_axis.x_start = fract->vars.complex_axis.x_start
		* fract->vars.zoom;
	fract->vars.complex_axis.x_end = fract->vars.complex_axis.x_end
		* fract->vars.zoom;
	fract->vars.complex_axis.y_start = fract->vars.complex_axis.y_start
		* fract->vars.zoom;
	fract->vars.complex_axis.y_end = fract->vars.complex_axis.y_end
		* fract->vars.zoom;
	fract->vars.move *= fract->vars.zoom;
}
