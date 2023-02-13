/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:38:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:48:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				put_fract_to_image(t_fract *fract)
{
	if (fract->mlx_vars->fract == 1)
		if (!(put_mandelbrot(fract)))
			return (0);
	if (fract->mlx_vars->fract == 2)
		if (!(put_julia(fract)))
			return (0);
	// if (fract->mlx_vars->fract == 3)
	// 	if (!(put_burningship(fract)))
	// 		return (0);
	return (1);
}