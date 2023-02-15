/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:09 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_fract *fract)
{
    
}

void iterate_julia(t_fract *fract)
{
    
}

void render_julia(t_fract *fract)
{
    fract->vars->x = 0;
    while (fract->vars->x < WIDTH)
    {
        fract->vars->y = 0;
        while (fract->vars->y < HIGHT)
        {
            //iterate_julia(fract);
            fract->vars->color = 0xFFFFFF;
            mlx_put_pixel_img(fract);
            fract->vars->y++;
        }
        fract->vars->x++;
    }
}