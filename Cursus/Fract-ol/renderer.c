/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

void	render_fract(t_fract *fract)
{
	render(fract);
	put_sidebar(fract);
}

void	mlx_put_pixel_img(t_fract *fract)
{
	char	*dst;

	dst = fract->img_vars.addr + (fract->vars.win_axis.y
			* fract->img_vars.line_lenght + fract->vars.win_axis.x
			* (fract->img_vars.bpp / 8));
	*(unsigned int *)dst = fract->vars.colors.color;
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
