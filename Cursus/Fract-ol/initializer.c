/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:05:31 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:55:10 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_fract	*init_mlx(void)
{
	t_fract	*fract;

	if (!(fract = malloc(sizeof(t_fract))))
		return (0);
	if (!(fract->mlx_vars = malloc(sizeof(t_mlx_var))))
		return (0);
	if (!(fract->vars = malloc(sizeof(t_fract_vars))))
		return (0);
	if (!(fract->inputs = malloc(sizeof(t_input))))
		return (0);
	fract->mlx_vars->mlx_p = mlx_init();
	fract->mlx_vars->win_p = mlx_new_window(fract->mlx_vars->mlx_p, WIDTH, WIDTH, "fractol");
	fract->mlx_vars->img_p = mlx_new_image(fract->mlx_vars->mlx_p, WIDTH, WIDTH);
	fract->mlx_vars->tab = (unsigned int *)mlx_get_data_addr(fract->mlx_vars->img_p,
			&fract->mlx_vars->bpp, &fract->mlx_vars->line_length, &fract->mlx_vars->endian);
	fract->inputs->color_id = 1;
	return (fract);
}

void		init_fract_type(char *input_name, t_fract *fract)
{
	if (!ft_strcmp(input_name, "mandelbrot"))
	{
		init_mandelbrot(fract);
		fract->mlx_vars->fract = 1;
	}
	else if (!ft_strcmp(input_name, "julia"))
	{
		init_julia(fract);
		fract->mlx_vars->fract = 2;
	}
	// else if (!ft_strcmp(input_name, "burningship"))
	// {
	// 	init_burningship(fract);
	// 	fract->mlx_vars->fract = 3;
	// }
}