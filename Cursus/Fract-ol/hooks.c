/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 16:33:50 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static void	text_flashing_color(t_fract *fract)
{
	static int	counter;

	if (fract->vars.text_color == RED && counter == 7)
	{
		fract->vars.text_color = WHITE;
		counter = 0;
	}
	else if (fract->vars.text_color == WHITE && counter == 2)
	{
		fract->vars.text_color = RED;
		counter = 0;
	}
	counter++;
}

int	handle_keypress(int keycode, t_fract *fract)
{
	if (keycode == K_ESC)
		exit_program(fract);
	if (keycode == K_C)
		reset_fract(fract);
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGTH_ARROW
		|| keycode == K_UP_ARROW || keycode == K_DOWN_ARROW)
		move_fract(fract, keycode);
	else if (keycode == K_A || keycode == K_R || keycode == K_G
		|| keycode == K_B || keycode == K_S || keycode == K_D
		|| keycode == K_F || keycode == K_Q)
		ft_move_color(fract, keycode);
	else if (keycode == K_P || keycode == K_SPACEBAR || keycode == K_7)
		pause_upause(fract, keycode);
	else if (keycode == K_I || keycode == K_O)
		controlle_iteration_nb(fract, keycode);
	else if (keycode == K_1 || keycode == K_2 || keycode == K_3
		|| keycode == K_4 || keycode == K_5)
		switch_fract(fract, keycode);
	else if (keycode == K_PLUS || keycode == K_MINUS
		|| keycode == K_NUM_PLUS || keycode == K_NUM_MINUS)
		handle_keyboard_zoom(fract, keycode);
	else if (keycode == K_6)
		fract->vars.switch_color_formula = ! fract->vars.switch_color_formula;
	render_fract(fract);
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_fract *fract)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		handle_mouse_zoom(fract, x, y, button);
	render_fract(fract);
	return (0);
}

static void	color_cycle(t_fract *fract)
{
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
}

int	loop_hook(t_fract *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if ((fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID
			|| fract->vars.id == CUSTOM_JULIA_ID)
		&& fract->vars.pause_julia == 1)
	{
		mlx_mouse_get_pos(fract->mlx_vars.win_ptr, &x, &y);
		fract->vars.c.real = coodinates_converter_x(x, fract);
		fract->vars.c.imag = coodinates_converter_y(y, fract);
	}
	text_flashing_color(fract);
	color_cycle(fract);
	render_fract(fract);
	return (0);
}
