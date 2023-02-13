/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:42:55 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:35:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		init_mandelbrot(t_fract *fract)
{
	fract->inputs->move_x = -2;
	fract->inputs->move_y = -1.5;
	fract->inputs->zoom = 300;
	fract->inputs->iteration_max = 50;
}

void	calc_mandelbrot(t_mlx_var *mlx_vars, t_fract_vars *var, t_input *inputs)
{
	int				i;
	double			tmp;

	var->const_real = var->x / inputs->zoom + inputs->move_x;
	var->const_imag = var->y / inputs->zoom + inputs->move_y;
	var->z_real = 0;
	var->z_imag = 0;
	i = 0;
	while (var->z_real * var->z_real + var->z_imag *
			var->z_imag < 4 && i < inputs->iteration_max)
	{
		tmp = var->z_real;
		var->z_real = var->z_real * var->z_real - var->z_imag *
			var->z_imag + var->const_real;
		var->z_imag = 2 * tmp * var->z_imag + var->const_imag;
		i++;
	}
	if (inputs->color_id != 1)
		if (i == inputs->iteration_max)
			mlx_vars->tab[var->y * WIDTH + var->x] = 0;
		else
			mlx_vars->tab[var->y * WIDTH + var->x] = i * inputs->color_value;
	else
		color(mlx_vars, var, inputs, i);
}

int			put_mandelbrot(t_fract *fract)
{
	char	*it;

	fract->vars->x = 0;
	bzero_tab(fract->mlx_vars->tab);
	while (fract->vars->x < WIDTH)
	{
		fract->vars->y = 0;
		while (fract->vars->y < WIDTH)
		{
			calc_mandelbrot(fract->mlx_vars, fract->vars, fract->inputs);
			fract->vars->y++;
		}
		fract->vars->x++;
	}
	mlx_put_image_to_window(fract->mlx_vars->mlx_p, fract->mlx_vars->win_p,
			fract->mlx_vars->img_p, 0, 0);
	mlx_string_put(fract->mlx_vars->mlx_p, fract->mlx_vars->win_p, 20, 20, 16777215,
			"ITERATION MAX : ");
	if (!(it = ft_itoa(fract->inputs->iteration_max)))
		return (0);
	mlx_string_put(fract->mlx_vars->mlx_p, fract->mlx_vars->win_p, 180, 20, 16777215, it);
	free(it);
	return (1);
}