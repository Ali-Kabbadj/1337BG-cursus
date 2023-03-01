/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:14:48 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 17:27:44 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static double	mouse_x_complexe(double x, t_fract *fract)
{
	return ((x - (WIN_WIDTH - IMAGE_WIDTH)) * (fract->vars.complex_axis.x_end
			- fract->vars.complex_axis.x_start) / IMAGE_WIDTH
		+ fract->vars.complex_axis.x_start);
}

static double	mouse_y_complexe(double y, t_fract *fract)
{
	return (fract->vars.complex_axis.y_end - (y
			* (fract->vars.complex_axis.y_end
				- fract->vars.complex_axis.y_start) / IMAGE_HIGHT));
}

void	handle_keyboard_zoom(t_fract *fract, int keycode)
{
	if (keycode == K_NUM_PLUS || keycode == K_PLUS)
		fract->vars.zoom = ZOOM_IN;
	else if (keycode == K_NUM_MINUS || keycode == K_MINUS)
		fract->vars.zoom = ZOOM_OUT;
	cal_centered_zoom(fract);
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
	if (fract->vars.mouse_zoom_to_center == 0)
		cal_local_zoom(fract, mouse_x, mouse_y);
	else if (fract->vars.mouse_zoom_to_center == 1)
		cal_centered_zoom(fract);
}
