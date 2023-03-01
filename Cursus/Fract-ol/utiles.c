/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:44:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	default_shared(t_fract *fract)
{
	fract->vars.zoom = 0.9;
	fract->vars.max_iteration = 20;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.iterations = 0;
	fract->vars.move = 0.09;
	fract->vars.color_turn = 0;
	fract->vars.pause_color_cycle = 0;
	fract->vars.colors.transparency = 0;
	fract->vars.colors.red = 0;
	fract->vars.colors.green = 0;
	fract->vars.colors.blue = 0;
	fract->vars.text_color = RED;
}

void	reset_fract(t_fract *fract)
{
	init_fract_name(fract);
	init_vars(fract);
}
