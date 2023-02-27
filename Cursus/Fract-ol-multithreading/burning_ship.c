/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:03:32 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 16:46:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iteration_burning_ship_on_one_point(t_fract *fract)
{
	fract->vars.z.real = 0;
	fract->vars.z.imag = 0;
	while (fract->vars.iterations < fract->vars.max_iteration
		&& absolute_value(fract->vars.z) <= 400)
	{
		burning_ship_formula(&fract->vars.z, fract);
		fract->vars.iterations++;
	}
	set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
	fract->vars.iterations = 0;
	mlx_put_pixel_img(fract);
}

void *iterate_burning_ship(void *param)
{
	t_fract *fract;
    t_fract *fract_copy;
    int i;
    int j;
    
    fract = (t_fract *)param;
    fract_copy = malloc(sizeof(t_fract));
    *fract_copy = *fract;
    i = fract->vars.win_axis.x;
    while (i < fract->vars.win_axis.x + (WIDTH / THREADS))
    {
        j = 0;
        while (j < HIGHT)
        {
            fract_copy->vars.win_axis.x = i;
            fract_copy->vars.win_axis.y = j;
            iteration_burning_ship_on_one_point(fract_copy);
            j++;
        }
        i++;
    }
    free(fract_copy);
    return (0);
}

void	render_burning_ship(t_fract *fract)
{
    iterate_multithreading(fract);
}