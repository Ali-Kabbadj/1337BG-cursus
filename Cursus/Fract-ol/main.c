/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:46:30 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:32:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fractol.h"

int				main(int ac, char **av)
{
	t_fract	*fract;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")
				&& ft_strcmp(av[1], "burningship"))
		{
			//ft_putstr("Usage <filename> [mandelbrot/julia/burningship]\n");
			return (0);
		}
		if (!(fract = init_mlx()))
			return (0);
		init_fract_type(av[1], fract);
		if (!(put_fract_to_image(fract)))
			return (0);
		mlx_mouse_hook(fract->mlx_vars->win_p, mouse_hook, fract);
		mlx_hook(fract->mlx_vars->win_p, 2, 0, key_hook, fract);
		mlx_hook(fract->mlx_vars->win_p, 6, 1L << 6, julia_hook, fract);
		mlx_loop(fract->mlx_vars->mlx_p);
	}
	//ft_putstr("Usage <filename> [mandelbrot/julia/burningship]\n");
	return (0);
}