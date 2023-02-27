/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 20:16:23 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*itof(double n)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * 20);
	if (n < 0)
	{
		str[j] = '-';
		j++;
		n = n * -1;
	}
	while (n > 1)
	{
		n = n / 10;
		i++;
	}
	while (i >= 0)
	{
		str[j] = (int)n + 48;
		n = n - (int)n;
		n = n * 10;
		j++;
		i--;
	}
	str[j] = '.';
	j++;
	while (k < 5)
	{
		str[j] = (int)n + 48;
		n = n - (int)n;
		n = n * 10;
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}





static void put_info(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 30,
			0xFFFFFF, ft_strjoin("MAX ITERATIONS : ",
				ft_itoa(fract->vars.max_iteration)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 50,0xFFFFFF,"COLOR ------------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 70,0xFFFFFF, ft_strjoin("	ALPHA : ", ft_itoa(fract->vars.colors.transparency)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 90,0xFFFFFF,ft_strjoin("	RED   : ", ft_itoa(fract->vars.colors.red)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 110,0xFFFFFF,ft_strjoin("	GREEN : ", ft_itoa(fract->vars.colors.green)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 130,0xFFFFFF,ft_strjoin("	BLUE  : ", ft_itoa(fract->vars.colors.blue)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 150,0xFFFFFF,"COORDINATES ------------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 170,0xFFFFFF, ft_strjoin("X_Start : ", itof(fract->vars.complex_axis.x_start)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 190,0xFFFFFF, ft_strjoin("X_End   : ", itof(fract->vars.complex_axis.x_end)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 210,0xFFFFFF, ft_strjoin("Y_Start : ", itof(fract->vars.complex_axis.y_start)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 230,0xFFFFFF, ft_strjoin("Y_End   : ", itof(fract->vars.complex_axis.y_end)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 250,0xFFFFFF,"ZOOM ------------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 270,0xFFFFFF, ft_strjoin("ZOOM : ", ft_itoa(fract->vars.zoom)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 290,0xFFFFFF,"MOUSE ------------------");
}

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
	else if (fract->vars.id == CUSTOM_JULIA_ID)
		render_custom_julia(fract);
	put_info(fract);
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
