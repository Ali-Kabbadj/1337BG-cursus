/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:14:48 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:47:35 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static double	mouse_x_complexe(double x, t_fract *fract)
{
	return ((x - (WIN_WIDTH - IMAGE_WIDTH)) * (fract->vars.complex_axis.x_end
			- fract->vars.complex_axis.x_start) / WIN_WIDTH
		+ fract->vars.complex_axis.x_start);
}

static double	mouse_y_complexe(double y, t_fract *fract)
{
	return (fract->vars.complex_axis.y_end - (y
			* (fract->vars.complex_axis.y_end
				- fract->vars.complex_axis.y_start) / IMAGE_HIGHT));
}

static void	cal_bouderies_x_y_center(t_fract *fract, double mouse_x,
		double mouse_y)
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

void	handle_keyboard_zoom(t_fract *fract, int keycode)
{
	if (keycode == K_NUM_PLUS || keycode == K_PLUS)
		fract->vars.zoom = ZOOM_IN;
	else if (keycode == K_NUM_MINUS || keycode == K_MINUS)
		fract->vars.zoom = ZOOM_OUT;
	cal_bouderies_x_y_center(fract, 0, 0);
}

void	handle_mouse_zoom(t_fract *fract, int x, int y, int button)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = mouse_x_complexe(x, fract);
	mouse_y = mouse_y_complexe(y, fract);
	if (button == MOUSE_SCROLL_DOWN)
		fract->vars.zoom = ZOOM_IN;
	else
		fract->vars.zoom = ZOOM_OUT;
	cal_bouderies_x_y_center(fract, mouse_x, mouse_y);
}
