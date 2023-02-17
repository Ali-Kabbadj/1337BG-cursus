/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/17 00:56:50 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_fract(t_fract *fract)
{
    // if (fract->vars->id == 1)
    //     render_julia(fract);
	 if (fract->vars->id == 2)
    {
		render_mandelbrot(fract);
    }
}
