/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:09:42 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 00:17:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fract_name(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID)
		fract->vars.name = "JULIA";
	else if (fract->vars.id == MANDELBROT_ID)
		fract->vars.name = "MANDELBROT";
	else if (fract->vars.id == BURNING_SHIP_ID)
		fract->vars.name = "BURNING SHIP";
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
		fract->vars.name = "BURNING SHIP JULIA";
	else if (fract->vars.id == CUSTOM_JULIA_ID)
		fract->vars.name = "CUSTOM JULIA";
}

void	init_fract_type(t_fract *fract, char *name)
{
	if (ft_strcmp(name, "julia") == 0)
		fract->vars.id = JULIA_ID;
	else if (ft_strcmp(name, "mandelbrot") == 0)
		fract->vars.id = MANDELBROT_ID;
	else if (ft_strcmp(name, "burning_ship") == 0)
		fract->vars.id = BURNING_SHIP_ID;
	else if (ft_strcmp(name, "burning_ship_julia") == 0)
		fract->vars.id = BURNING_SHIP_JULIA_ID;
	else if (ft_strcmp(name, "custom_julia") == 0)
		fract->vars.id = CUSTOM_JULIA_ID;
}

void	init_img(t_fract *fract)
{
	fract->img_vars.img = mlx_new_image(fract->mlx_vars.mlx_ptr, WIDTH, HIGHT);
	fract->img_vars.addr = mlx_get_data_addr(fract->img_vars.img,
												&(fract->img_vars.bpp),
												&(fract->img_vars.line_lenght),
												&(fract->img_vars.endian));
	fract->img.img = mlx_new_image(fract->mlx_vars.mlx_ptr, CUSTOM_WIDTH - WIDTH, 1000);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp, &fract->img.line_lenght, &fract->img.endian);
}

void	init_mlx_vars(t_fract *fract)
{
	fract->mlx_vars.mlx_ptr = mlx_init();
	if (fract->mlx_vars.mlx_ptr == NULL)
		exit_program(fract);
	fract->mlx_vars.win_ptr = mlx_new_window(fract->mlx_vars.mlx_ptr, CUSTOM_WIDTH,
		HIGHT, "FRACTOL");
	if (fract->mlx_vars.win_ptr == NULL)
		exit_program(fract);
}

int	init_hooks(t_fract *fract)
{
	mlx_key_hook(fract->mlx_vars.win_ptr, handle_keypress, fract);
	mlx_mouse_hook(fract->mlx_vars.win_ptr, handle_mouse_input, fract);
	mlx_hook(fract->mlx_vars.win_ptr, 17, 1L << 17, exit_program, fract);
	mlx_loop_hook(fract->mlx_vars.mlx_ptr, loop_hook, fract);
	return (0);
}

