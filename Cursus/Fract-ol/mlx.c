/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:03:33 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/20 03:20:21 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mlx_put_pixel_img(t_fract *fract)
{
    char *dst;

    dst = fract->img_vars.addr + (fract->vars.win_axis.y * fract->img_vars.line_lenght + fract->vars.win_axis.x * (fract->img_vars.bpp / 8));
    *(unsigned int *)dst = fract->vars.colors.color;
}