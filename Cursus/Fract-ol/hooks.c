/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:02:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:21:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_window(t_mlx_var *id)
{
	mlx_destroy_window(id->mlx_p, id->win_p);
	free(id->tab);
	exit(0);
}

void	move(int key, t_input *inp)
{
	if (key == 123)
		inp->move_x += 30 / inp->zoom;
	if (key == 124)
		inp->move_x -= 30 / inp->zoom;
	if (key == 125)
		inp->move_y -= 30 / inp->zoom;
	if (key == 126)
		inp->move_y += 30 / inp->zoom;
}

void	zoom(int x, int y, t_input *inp)
{
	inp->move_x = (x / inp->zoom + inp->move_x) - (x / (inp->zoom * 1.3));
	inp->move_y = (y / inp->zoom + inp->move_y) - (y / (inp->zoom * 1.3));
	inp->zoom *= 1.3;
	inp->iteration_max++;
}

void	dezoom(int x, int y, t_input *inp)
{
	inp->move_x = (x / inp->zoom + inp->move_x) - (x / (inp->zoom / 1.3));
	inp->move_y = (y / inp->zoom + inp->move_y) - (y / (inp->zoom / 1.3));
	inp->zoom /= 1.3;
	inp->iteration_max--;
}

int		mouse_hook(int key, int x, int y, void *fract)
{
	if (key == 4 || key == 1)
		zoom(x, y, ((t_fract *)fract)->inputs);
	if (key == 5 || key == 2)
		dezoom(x, y, ((t_fract *)fract)->inputs);
	put_fract_to_image(fract);
	return (0);
}

int		key_hook(int key, void *fract)
{
	if (key == 53)
		destroy_window(((t_fract *)fract)->mlx_vars);
	if (key > 122 && key < 127)
		move(key, ((t_fract *)fract)->inputs);
	if (key == 69)
		((t_fract *)fract)->inputs->iteration_max += 1;
	if (key == 78)
		((t_fract *)fract)->inputs->iteration_max -= 1;
	if (key == 30)
		((t_fract *)fract)->inputs->iteration_max += 500;
	if (key == 33)
		if (((t_fract *)fract)->inputs->iteration_max - 500 > 0)
			((t_fract *)fract)->inputs->iteration_max -= 500;
	if (key == 35)
	{
		if (((t_fract *)fract)->inputs->pause == 1)
			((t_fract *)fract)->inputs->pause = 0;
		else
			((t_fract *)fract)->inputs->pause = 1;
	}
	if (key > 17 && key < 22)
		color_input(key, ((t_fract *)fract)->inputs);
	put_fract_to_image(fract);
	return (0);
}

int			julia_hook(int x, int y, void *fract)
{
	if (((t_fract *)fract)->inputs->pause == 0 && ((t_fract *)fract)->mlx_vars->fract == 2)
	{
		((t_fract *)fract)->vars->const_real = (double)x / 500 - 1.3;
		((t_fract *)fract)->vars->const_imag = (double)y / 500 - 1.3;
		put_fract_to_image(fract);
	}
	return (0);
}