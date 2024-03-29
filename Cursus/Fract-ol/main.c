/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:38:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 13:18:17 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

int	main(int ac, char **av)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	handle_input(ac, av, fract);
	if (!fract)
		return (0);
	init_fract_type(fract, av[1]);
	init_mlx_vars(fract);
	init_img(fract);
	init_vars(fract);
	init_hooks(fract);
	render_fract(fract);
	mlx_loop(fract->mlx_vars.mlx_ptr);
	return (0);
}
