/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:25 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 16:33:47 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia(t_fract *fract)
{
	fract->inputs->move_x = -2;
	fract->inputs->move_y = -1.5;
	fract->inputs->pause = 0;
	fract->vars->const_real = -0.9;
	fract->vars->const_imag = 0.305;
	fract->inputs->zoom = 300;
	fract->inputs->iteration_max = 50;
}

static void	calc_julia(t_mlx_var *mlx_vars, t_fract_vars *fract_vars, t_input *inp)
{
	int		i;
	double	tmp;

	i = 0;
	fract_vars->z_real = fract_vars->x / inp->zoom + inp->move_x;
	fract_vars->z_imag = fract_vars->y / inp->zoom + inp->move_y;
	while (fract_vars->z_real * fract_vars->z_real + fract_vars->z_imag * fract_vars->z_imag < 4 && i < inp->iteration_max)
	{
		tmp = fract_vars->z_real;
		fract_vars->z_real = fract_vars->z_real * fract_vars->z_real - fract_vars->z_imag * fract_vars->z_imag + fract_vars->const_real;
		fract_vars->z_imag = 2 * fract_vars->z_imag * tmp + fract_vars->const_imag;
		i++;
	}
	if (inp->color_id != 1)
		if (i == inp->iteration_max)
			mlx_vars->tab[fract_vars->y * WIDTH + fract_vars->x] = 0;
		else
			mlx_vars->tab[fract_vars->y * WIDTH + fract_vars->x] = i * inp->color_value;
	else
		color(mlx_vars, fract_vars, inp, i);
}

int			put_julia(t_fract *fract)
{
	char	*it;

	fract->vars->x = 0;
	bzero_tab(fract->mlx_vars->tab);
	while (fract->vars->x < WIDTH)
	{
		fract->vars->y = 0;
		while (fract->vars->y < WIDTH)
		{
			calc_julia(fract->mlx_vars, fract->vars, fract->inputs);
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