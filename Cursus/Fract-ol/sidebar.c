/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:17:29 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 13:20:41 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

void	put_color_info(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 50,
		BLACK, "------------------ ARGB ---------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 70,
		BLACK, "ALPHA : ");
	put_int_to_win(fract, 265, 70, fract->vars.colors.transparency);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 90,
		RED, "RED   : ");
	put_int_to_win(fract, 265, 90, fract->vars.colors.red);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 110,
		GREEN, "GREEN : ");
	put_int_to_win(fract, 265, 110, fract->vars.colors.green);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 130,
		BLUE, "BLUE  : ");
	put_int_to_win(fract, 265, 130, fract->vars.colors.blue);
}

void	put_menu1(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 150,
		BLACK, "----------------- MANUAL --------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 170,
		BLACK, "|  KEYS  |          ACTIONS           |");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 190,
		BLACK, "---------------------------------------");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 210,
		BLACK, "  WHEELS |        ZOOM");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 230,
		BLACK, "     I   |        INCREASE ITERATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 250,
		BLACK, "     O   |        DECREASE ITERATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 270,
		BLACK, "    ->   |        MOVE RIGHT");
}

void	put_menu2(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 290,
		BLACK, "    <-   |        MOVE LEFT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 310,
		BLACK, "     ^   |        MOVE UP");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 330,
		BLACK, "     v   |        MOVE DOWN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 350,
		BLACK, "     C   |        RESET");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 370,
		BLACK, "     R   |        INCREACE RED");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 390,
		BLACK, "     G   |        INCREACE GREEN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 410,
		BLACK, "     B   |        INCREACE BLUE");
}

void	put_menu3(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 430,
		BLACK, "     A   |        INCREACE ALPHA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 450,
		BLACK, "     S   |        DECREACE RED");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 470,
		BLACK, "     D   |        DECREACE GREEN");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 490,
		BLACK, "     F   |        DECREACE BLUE");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 510,
		BLACK, "     Q   |        DECREACE ALPHA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 530,
		BLACK, "     1   |        JULIA");
}

void	put_menu4(t_fract *fract)
{
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 550,
		BLACK, "     2   |        MANDELBROT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 570,
		BLACK, "     3   |        BURNING SHIP");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 590,
		BLACK, "     4   |        BURNING SHIP JULIA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 610,
		BLACK, "     5   |        CUSTOM JULIA");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 630,
		BLACK, "     6   |        SMOOTH COLORING ON/OFF");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 650,
		BLACK, "     7   |        CENTERED ZOOM ON/OFF");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 670,
		BLACK, "     P   |        PAUSE JULIAS MOUSE HOOK");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 690,
		BLACK, "   SPACE |        PAUSE COLOR ANIMATION");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 710,
		BLACK, "    +/-  |        CENTERED ZOOM");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 730,
		BLACK, "    ESC  |        EXIT");
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 25, 978,
		BLACK, "   MADE WITH LOVE BY AKABBADJ  <3 ");
}
