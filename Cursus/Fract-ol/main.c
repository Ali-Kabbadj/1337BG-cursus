/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:38:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/18 16:28:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fract *fract;
	if (ac != 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1],
				"mandelbrot")))
	{
		ft_printf("Syntax : ./fractol <julia> or <mandelbrot>");
		return (0);
	}
	fract = malloc(sizeof(t_fract));
	if (!fract)
		return (0);
	init_structs(fract);
	init_fract_type(fract, av[1]);
	init_mlx_vars(fract);
	init_img(fract);
	one_time_init(fract);
	render_fract(fract);	
	init_hooks(fract);
	mlx_loop(fract->mlx_vars->mlx_ptr);
	return (0);
}