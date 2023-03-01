/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 02:25:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel_1(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void color_bars(t_fract *fract)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 1000)
	{
		while (j < 300)
		{
			if (i > 60 && i < 70 && j > 75 && j < 260)
				mlx_put_pixel_1(&fract->img, j, i, ((int)fract->vars.colors.transparency << 24) | 255 << 16 | 255 << 8 | 255);
			else if (i > 80 && i < 90 && j > 75 && j < 260)
				mlx_put_pixel_1(&fract->img, j, i, ((int)fract->vars.colors.transparency << 24) | ((int)fract->vars.colors.red) << 16);
			else if (i > 100 && i < 110 && j > 75 && j < 260)
				mlx_put_pixel_1(&fract->img, j, i, ((int)fract->vars.colors.transparency << 24) | ((int)fract->vars.colors.green) << 8);
			else if (i > 120 && i < 130 && j > 75 && j < 260)
				mlx_put_pixel_1(&fract->img, j, i, ((int)fract->vars.colors.transparency << 24) | ((int)fract->vars.colors.blue));
			else 
				mlx_put_pixel_1(&fract->img, j, i, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, fract->img.img, 0, 0);
}

static void put_color_info(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 50,0x000000,"------------------ ARGB ---------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 70,0x000000,"ALPHA : ");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 265, 70,0x000000, ft_itoa(fract->vars.colors.transparency));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 90, 0x000000 ,"RED   : ");;
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 265, 90,0x000000, ft_itoa(fract->vars.colors.red));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 110,0x000000,"GREEN : ");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 265, 110,0x000000, ft_itoa(fract->vars.colors.green));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 130,0x000000,"BLUE  : ");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 265, 130,0x000000, ft_itoa(fract->vars.colors.blue));
}

static void put_menu1(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 150,0x000000,"----------------- MANUAL --------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 170,0x000000,"|  KEYS  |          ACTIONS           |");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 190,0x000000,"---------------------------------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 210,0x000000,"   WHEEL |        ZOOM");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 230,0x000000,"     I   |        INCREASE ITERATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 250,0x000000,"     O   |        DECREASE ITERATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 270,0x000000,"    ->   |        MOVE RIGHT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 290,0x000000,"    <-   |        MOVE LEFT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 310,0x000000,"     ^   |        MOVE UP");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 330,0x000000,"     v   |        MOVE DOWN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 350,0x000000,"     C   |        RESET");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 370,0x000000,"     R   |        INCREACE RED");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 390,0x000000,"     G   |        INCREACE GREEN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 410,0x000000,"     B   |        INCREACE BLUE");
}

static void put_menu2(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 430,0x000000,"     A   |        INCREACE ALPHA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 450,0x000000,"     S   |        DECREACE RED");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 470,0x000000,"     D   |        DECREACE GREEN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 490,0x000000,"     F   |        DECREACE BLUE");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 510,0x000000,"     Q   |        DECREACE ALPHA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 530,0x000000,"     1   |        JULIA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 550,0x000000,"     2   |        MANDELBROT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 570,0x000000,"     3   |        BURNING SHIP");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 590,0x000000,"     4   |        BURNING SHIP JULIA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 610,0x000000,"     5   |        CUSTOM JULIA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 630,0x000000,"     P   |        PAUSE JULIAS MOUSE HOOK");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 650,0x000000,"   SPACE |        PAUSE COLOR ANIMATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 670,0x000000,"    ESC  |        EXIT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 990,0x000000,"   made  with  love  by  akabbadj  <3 ");
}

static void put_data_info(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 30,0x000000, ft_strjoin("CURRENT FRACTAL : ", fract->vars.name));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 20, fract->vars.text_color, ft_strjoin("MAX ITERATIONS : ",ft_itoa(fract->vars.max_iteration)));
}

void text_flashing_color(t_fract *fract)
{
	static int counter = 0;
	if (fract->vars.text_color == 0xFF0000 && counter == 7)
	{
		fract->vars.text_color = 0xFFFFFF;
		counter = 0;
	}
	else if (fract->vars.text_color == 0xFFFFFF && counter == 5)
	{
		fract->vars.text_color = 0xFF0000;
		counter = 0;
	}
	counter++;
}

static void put_info(t_fract *fract)
{
	color_bars(fract);
	put_color_info(fract);
	put_data_info(fract);
	put_menu1(fract);
	put_menu2(fract);
	if (fract->vars.id == JULIA_ID || fract->vars.id == BURNING_SHIP_JULIA_ID || fract->vars.id == CUSTOM_JULIA_ID)
	{
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 930, fract->vars.text_color, "Fractal manipilation with mouse");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 950, fract->vars.text_color, "pointer is available !");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 970, fract->vars.text_color, "Click P and move mouse pointer");
		mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 310, 990, fract->vars.text_color, "to see the magic !");
	}
}

void	render_fract(t_fract *fract)
{
	render(fract);
	put_info(fract);
}

void	mlx_put_pixel_img(t_fract *fract)
{
	char	*dst;

	dst = fract->img_vars.addr + (fract->vars.win_axis.y
			* fract->img_vars.line_lenght + fract->vars.win_axis.x
			* (fract->img_vars.bpp / 8));
	*(unsigned int *)dst = fract->vars.colors.color;
}

void render(t_fract *fract)
{
	fract->vars.win_axis.x = 0;
	while (fract->vars.win_axis.x < WIDTH)
	{
		fract->vars.win_axis.y = 0;
		while (fract->vars.win_axis.y < HIGHT)
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
