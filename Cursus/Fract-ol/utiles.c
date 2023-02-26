/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 13:23:45 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	dispose_mlx_vars(t_fract *fract)
{
	if (fract->mlx_vars.mlx_ptr)
	{
		mlx_destroy_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
		free(fract->mlx_vars.mlx_ptr);
	}
}

int	exit_program(t_fract *fract)
{
	dispose_mlx_vars(fract);
	if (fract)
		free(fract);
	exit(0);
}

char	*get_win_title(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID)
		return (JULIA_WIN_NAME);
	else if (fract->vars.id == MANDELBROT_ID)
		return (MANDELBROT_WIN_NAME);
	else if (fract->vars.id == BURNING_SHIP_ID)
		return (BURNING_SHIP_WIN_NAME);
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
		return (BURNING_SHIP_JULIA_WIN_NAME);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
