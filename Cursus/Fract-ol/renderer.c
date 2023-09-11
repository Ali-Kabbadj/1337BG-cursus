/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 12:53:36 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

void	render_fract(t_fract *fract)
{
	render(fract);
	put_sidebar(fract);
}

void	mlx_put_pixel_img(t_img_data *img_vars, int x, int y, int color)
{
	char	*dst;

	dst = img_vars->addr + (y * img_vars->line_lenght + x
			* (img_vars->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render(t_fract *fract)
{
	fract->vars.win_axis.x = 0;
	while (fract->vars.win_axis.x < IMAGE_WIDTH)
	{
		fract->vars.win_axis.y = 0;
		while (fract->vars.win_axis.y < IMAGE_HIGHT)
		{
			iteration(fract);
			fract->vars.win_axis.y++;
		}
		fract->vars.win_axis.x++;
	}
	mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
		fract->img_vars.img, 300, 0);
}
