/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:38:35 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

static void	mlx_put_pixel_side_bar(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	decide_pixel_color(t_fract *fract, int j, int i)
{
	if (i > 60 && i < 70 && j > 75 && j < 260)
		mlx_put_pixel_side_bar(&fract->img, j, i,
			((int)fract->vars.colors.transparency << 24)
			| 255 << 16 | 255 << 8 | 255);
	else if (i > 80 && i < 90 && j > 75 && j < 260)
		mlx_put_pixel_side_bar(&fract->img, j, i,
			((int)fract->vars.colors.transparency << 24)
			| ((int)fract->vars.colors.red) << 16);
	else if (i > 100 && i < 110 && j > 75 && j < 260)
		mlx_put_pixel_side_bar(&fract->img, j, i,
			((int)fract->vars.colors.transparency << 24)
			| ((int)fract->vars.colors.green) << 8);
	else if (i > 120 && i < 130 && j > 75 && j < 260)
		mlx_put_pixel_side_bar(&fract->img, j, i,
			((int)fract->vars.colors.transparency << 24)
			| ((int)fract->vars.colors.blue));
	else
		mlx_put_pixel_side_bar(&fract->img, j, i, WHITE);
}

static void	color_bars(t_fract *fract)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIDEBAR_WIDTH)
	{
		while (j < SIDEBAR_HEIGHT)
		{
			decide_pixel_color(fract, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
		fract->img.img, 0, 0);
}

static void	put_data_info(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 30,
		BLACK, ft_strjoin("CURRENT FRACTAL : ", fract->vars.name));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 20,
		fract->vars.text_color, ft_strjoin("MAX ITERATIONS : ",
			ft_itoa(fract->vars.max_iteration)));
}

void	put_sidebar(t_fract *fract)
{
	color_bars(fract);
	put_color_info(fract);
	put_data_info(fract);
	put_menu1(fract);
	put_menu2(fract);
	put_menu3(fract);
	put_menu4(fract);
	if (fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID
		|| fract->vars.id == CUSTOM_JULIA_ID)
	{
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310,
			930, fract->vars.text_color, "Fractal manipilation with mouse");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310,
			950, fract->vars.text_color, "pointer is available !");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310,
			970, fract->vars.text_color, "Click P and move mouse pointer");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310,
			990, fract->vars.text_color, "to see the magic !");
	}
}
