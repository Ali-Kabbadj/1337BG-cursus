/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/25 16:45:54 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fract(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID)
		render_julia(fract);
	else if (fract->vars.id == MANDELBROT_ID)
		render_mandelbrot(fract);
	else if (fract->vars.id == BURNING_SHIP_ID)
		render_burning_ship(fract);
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
		render_burning_ship_julia(fract);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 30,
			0xFFFFFF, ft_strjoin("MAX ITERATIONS : ",
				ft_itoa(fract->vars.max_iteration)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 60,
			0xFFFFFF, ft_strjoin("COLOR          : (",
				ft_strjoin(ft_itoa(fract->vars.colors.red), ft_strjoin(" , ",
						ft_strjoin(ft_itoa(fract->vars.colors.green),
							ft_strjoin(" , ",
								ft_strjoin(ft_itoa(fract->vars.colors.blue),
									")")))))));
}

void	rerender_fract(t_fract *fract)
{
	mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	render_fract(fract);
}

void	mlx_put_pixel_img(t_fract *fract)
{
	char	*dst;

	dst = fract->img_vars.addr + (fract->vars.win_axis.y
			* fract->img_vars.line_lenght + fract->vars.win_axis.x
			* (fract->img_vars.bpp / 8));
	*(unsigned int *)dst = fract->vars.colors.color;
}
