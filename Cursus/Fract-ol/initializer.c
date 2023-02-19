/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:09:42 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/19 02:18:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_structs(t_fract *fract)
{
	fract->mlx_vars = malloc(sizeof(t_mlx_vars));
	fract->vars = malloc(sizeof(t_vars));
	fract->img_vars = malloc(sizeof(t_img_data));
	if (fract->mlx_vars == NULL || fract->vars == NULL
		|| fract->img_vars == NULL)
		exit_program(fract);
}

void	init_fract_type(t_fract *fract, char *name)
{
	if (ft_strcmp(name, "julia") == 0)
		fract->vars->id = JULIA_ID;
	else if (ft_strcmp(name, "mandelbrot") == 0)
		fract->vars->id = MANDELBROT_ID;
}

void	init_img(t_fract *fract)
{
	fract->img_vars->img = mlx_new_image(fract->mlx_vars->mlx_ptr, WIDTH,
			HIGHT);
	fract->img_vars->addr = mlx_get_data_addr(fract->img_vars->img,
			&(fract->img_vars->bpp), &(fract->img_vars->line_lenght),
			&(fract->img_vars->endian));
}

void	init_mlx_vars(t_fract *fract)
{
	fract->mlx_vars->mlx_ptr = mlx_init();
	if (fract->mlx_vars->mlx_ptr == NULL)
		exit_program(fract);
	fract->mlx_vars->win_ptr = mlx_new_window(fract->mlx_vars->mlx_ptr, WIDTH,
			HIGHT, get_win_title(fract));
	if (fract->mlx_vars->win_ptr == NULL)
		dispose_mlx_vars(fract);
}

int init_hooks(t_fract *fract)
{
	mlx_key_hook(fract->mlx_vars->win_ptr, handle_keypress, fract);
    mlx_mouse_hook(fract->mlx_vars->win_ptr, handle_mouse_input, fract );
	mlx_loop_hook(fract->mlx_vars->mlx_ptr, julia_hook, fract);
	return(0);
}

void init_vars(t_fract *fract)
{
	if (fract->vars->id == 1)
        init_julia(fract);
    if (fract->vars->id == 2)
        one_time_init_mandelbrot(fract);
}
