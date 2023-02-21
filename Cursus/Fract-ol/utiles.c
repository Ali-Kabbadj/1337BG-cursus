/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/21 10:09:28 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_move_color(t_fract *fract, int key)
{
	if (key == K_R)
		fract->vars.colors.red++;
	if (key == K_G)
		fract->vars.colors.green++;
	if (key == K_B)
		fract->vars.colors.blue++;
}

float	coodinates_converter_x(float x, t_fract *fract)
{
	return (x * (fract->vars.complex_axis.x_end - fract->vars.complex_axis.x_start) / WIDTH
		+ fract->vars.complex_axis.x_start + fract->vars.move_x);
}

float	coodinates_converter_y(float y, t_fract *fract)
{
	return (fract->vars.complex_axis.y_end - (y * (fract->vars.complex_axis.y_end
				- fract->vars.complex_axis.y_start) / HIGHT + fract->vars.move_y));
}

void	exit_program(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	mlx_destroy_image(fract->mlx_vars.mlx_ptr, fract->img_vars.img);
	if (fract != NULL)
		free(fract);
	exit(0);
}

char	*get_win_title(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID)
		return (JULIA_WIN_NAME);
	else if (fract->vars.id == MANDELBROT_ID)
		return (MANDELBROT_WIN_NAME);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	dispose_mlx_vars(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	free(fract->mlx_vars.mlx_ptr);
	exit_program(fract);
}


void set_pixel_color(t_fract *fract, int iterations, t_complexe z)
{
	float red;
	float green;
	float blue;

	red = fract->vars.colors.red;
	green = fract->vars.colors.green;
	blue = fract->vars.colors.blue;

	float smooth_color = iterations + 1 - log(log(sqrt(z.real * z.real + z.imag * z.imag))) / log(2);
	red = fract->vars.colors.red * smooth_color;
	green = fract->vars.colors.green * smooth_color;
	blue = fract->vars.colors.blue * smooth_color;
	if (iterations == fract->vars.max_iteration)
	{
		fract->vars.colors.color= 0x000000;
		return;
	}
	else
	{
		fract->vars.colors.color = ((int)red << 16) | ((int)green << 8) | (int)blue;
	}
	
}



	
	
	
	