/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/19 00:34:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_move_color(t_fract *fract, int key)
{
	if (key == K_R)
		fract->vars->red++;
	if (key == K_G)
		fract->vars->green++;
	if (key == K_B)
		fract->vars->blue++;
}

float	coodinates_converter_x(float x, t_fract *fract)
{
	return (x * (fract->vars->re_end - fract->vars->re_start) / WIDTH
		+ fract->vars->re_start + fract->vars->move_x);
}

float	coodinates_converter_y(float y, t_fract *fract)
{
	return (fract->vars->imag_end - (y * (fract->vars->imag_end
				- fract->vars->imag_start) / HIGHT + fract->vars->move_y));
}

void	exit_program(t_fract *fract)
{
	if (fract->mlx_vars != NULL)
		free(fract->mlx_vars);
	if (fract->vars != NULL)
		free(fract->vars);
	if (fract->img_vars != NULL)
		free(fract->img_vars);
	if (fract != NULL)
		free(fract);
	exit(0);
}

char	*get_win_title(t_fract *fract)
{
	if (fract->vars->id == JULIA_ID)
		return (JULIA_WIN_NAME);
	else if (fract->vars->id == MANDELBROT_ID)
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
	mlx_destroy_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
	free(fract->mlx_vars->mlx_ptr);
	exit_program(fract);
}