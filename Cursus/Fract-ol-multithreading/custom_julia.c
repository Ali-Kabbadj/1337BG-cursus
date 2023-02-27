/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:20:17 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 00:51:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iteration_custom_julia_on_one_point(t_fract *fract)
{
	fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
	fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
	if (absolute_value(fract->vars.z) > 10 )
	{
		set_pixel_color(fract, fract->vars.max_iteration, fract->vars.z);
		mlx_put_pixel_img(fract);
		return ;
	}
	while (fract->vars.iterations < fract->vars.max_iteration
		&& absolute_value(fract->vars.z) <= 400)
	{
		custom_julia_formula(&fract->vars.z, fract->vars.c);
		fract->vars.iterations++;
	}
	set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
	fract->vars.iterations = 0;
	mlx_put_pixel_img(fract);
}


void	*iterate_custom_julia(void *param)
{
	t_fract *fract;
	t_fract *fract_copy;
	int i;
	int j;

	fract = (t_fract *)param;
	fract_copy = malloc(sizeof(t_fract));
	*fract_copy = *fract;
	i =fract->vars.win_axis.x;
	while (i < fract->vars.win_axis.x + (WIDTH / THREADS))
	{
		j = 0;
		while (j < HIGHT)
		{
			fract_copy->vars.win_axis.x = i;
			fract_copy->vars.win_axis.y = j;
			iteration_custom_julia_on_one_point(fract_copy);
			j++;
		}
		i++;
	}
	free(fract_copy);
	return (0);
}

void render_custom_julia(t_fract *fract)
{
	iterate_multithreading(fract);
}

