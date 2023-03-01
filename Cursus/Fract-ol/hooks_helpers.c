/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:26:12 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 01:08:33 by akabbadj         ###   ########.fr       */
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

void mouse_pointer_availability(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID || fract->vars.id == CUSTOM_JULIA_ID)
	{
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 700, 0xFF0000, "Mouse pointer manpulation is available");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 700, 0xFFFFFF, "Mouse pointer manpulation is available");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 700, 0xFF0000, "Click P to pause/unpause pointer influence");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 700, 0xFFFFFF, "Click P to pause/unpause pointer influence");
	}
}

void switch_fract(t_fract *fract, int keycode)
{
	int old_id;

	old_id = fract->vars.id;
	if (keycode == K_1 && fract->vars.id != 1)
		fract->vars.id = JULIA_ID;
	else if (keycode == K_2 && fract->vars.id != 2)
		fract->vars.id = MANDELBROT_ID;
	else if (keycode == K_3 && fract->vars.id != 3)
		fract->vars.id = BURNING_SHIP_ID;
	else if (keycode == K_4 && fract->vars.id != 4)
		fract->vars.id = BURNING_SHIP_JULIA_ID;
	else if (keycode == K_5 && fract->vars.id != 5)
		fract->vars.id = CUSTOM_JULIA_ID;
	if (old_id != fract->vars.id)
	{
		init_fract_name(fract);
		reset_fract(fract);
	}
}
