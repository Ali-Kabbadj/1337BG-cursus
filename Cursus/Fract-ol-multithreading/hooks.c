/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 21:28:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_fract *fract)
{
	if (keycode == K_ESC)
	{
		exit_program(fract);
		return (0);
	}
	if (keycode == K_C)
		default_fract(fract);
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGTH_ARROW
			|| keycode == K_UP_ARROW || keycode == K_DOWN_ARROW)
		move_fract(fract, keycode);
	else if (keycode == K_T || keycode == K_R || keycode == K_G || keycode == K_B)
		ft_move_color(fract, keycode);
	else if (keycode == K_P || keycode == K_SPACEBAR)
		pause_upause(fract, keycode);
	else if (keycode == K_I || keycode == K_O)
		controlle_iteration_nb(fract, keycode);
	rerender_fract(fract);
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_fract *fract)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		handle_zoom(fract, x, y, button);
	rerender_fract(fract);
	return (0);
}

int	loop_hook(t_fract *fract)
{
	int x, y;
	x = 0;
	y = 0;
	if ((fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID || fract->vars.id == CUSTOM_JULIA_ID)
		&& fract->vars.pause_julia == 1)
	{
		mlx_mouse_get_pos(fract->mlx_vars.win_ptr, &x, &y);
		fract->vars.c.real = coodinates_converter_x(x, fract);
		fract->vars.c.imag = coodinates_converter_y(y, fract);
	}
	if (fract->vars.pause_color_cycle == 0)
	{
		if (fract->vars.color_turn == 0)
		{
			fract->vars.colors.red += 1;
			fract->vars.color_turn = 1;
		}
		else if (fract->vars.color_turn == 1)
		{
			fract->vars.colors.green += 1;
			fract->vars.color_turn = 2;
		}
		else if (fract->vars.color_turn == 2)
		{
			fract->vars.colors.blue += 1;
			fract->vars.color_turn = 0;
		}
	}
	rerender_fract(fract);
	return (0);
}
