/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:26:12 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 14:23:36 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controlle_iteration_nb(t_fract *fract, int keycode)
{
	if (keycode == K_I)
		fract->vars.max_iteration += 5;
	else if (keycode == K_O && fract->vars.max_iteration - 5 >= 10)
		fract->vars.max_iteration -= 5;
}

void	move_fract(t_fract *fract, int keycode)
{
	if (keycode == K_UP_ARROW)
		fract->vars.move_y -= fract->vars.move;
	else if (keycode == K_DOWN_ARROW)
		fract->vars.move_y += fract->vars.move;
	else if (keycode == K_LEFT_ARROW)
		fract->vars.move_x -= fract->vars.move;
	else if (keycode == K_RIGTH_ARROW)
		fract->vars.move_x += fract->vars.move;
}

void	pause_upause(t_fract *fract, int keycode)
{
	if (keycode == K_P)
	{
		if (fract->vars.pause_julia == 1)
			fract->vars.pause_julia = 0;
		else
			fract->vars.pause_julia = 1;
	}
	else if (keycode == K_SPACEBAR)
	{
		if (fract->vars.pause_color_cycle == 1)
			fract->vars.pause_color_cycle = 0;
		else
			fract->vars.pause_color_cycle = 1;
	}
}
