/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:46:30 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 16:16:28 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int ac, char **av)
{
	t_fract	*fract;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot"))
		{
			return (0);
		}
		if (!(fract = init_mlx(av[1])))
			return (0);
		init_fract_type(av[1], fract);
		if (!(put_fract_to_image(fract)))
			return (0);
		init_hooks(fract);
		mlx_loop(fract->mlx_vars->mlx_p);
	}
	return (0);
}