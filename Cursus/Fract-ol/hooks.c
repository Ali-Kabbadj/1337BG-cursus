/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/16 22:27:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keycode ,t_fract *fract)
{
    if (keycode == 53)
        exit_program(fract);
    if (keycode == 126)
    {    
        fract->vars->move_y += 0.05;
        mlx_clear_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
        render_fract(fract);
    }   
    if (keycode == 125)
    {    
        fract->vars->move_y -= 0.05;
        mlx_clear_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
        render_fract(fract);
    }
    if (keycode == 123)
    {    
        fract->vars->move_x += 0.05;
        mlx_clear_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
        render_fract(fract);
    } 
    if (keycode == 124)
    {   
        fract->vars->move_x -= 0.05;
        mlx_clear_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
        render_fract(fract);
    } 
    return (0);
}

static int default_zoom(t_fract *fract , int x, int y)
{
    float d_re;
    float d_img;
    float s_re;
    float s_img;
    float old_re_start;
    float old_re_end;
    float old_img_start;
    float old_img_end;

    old_re_start = fract->vars->re_start;
    old_re_end = fract->vars->re_end;
    old_img_start = fract->vars->imag_start;
    old_img_end = fract->vars->imag_end;
    
    d_re = fract->vars->zoom * (fract->vars->re_end - coodinates_converter_x(x , fract));
    d_img = fract->vars->zoom * (fract->vars->imag_end - coodinates_converter_y(y, fract));
    s_re = (fract->vars->re_end - fract->vars->re_start) * fract->vars->zoom;
    s_img =  (fract->vars->imag_end - fract->vars->imag_start) * fract->vars->zoom;
    
    fract->vars->re_end = coodinates_converter_x(x, fract) - d_re;
    fract->vars->imag_end = coodinates_converter_y(y, fract) - d_img;
    fract->vars->re_start = fract->vars->re_end - s_re;
    fract->vars->imag_start = fract->vars->imag_end - s_img;
    
    fract->vars->move_x = d_re;
    fract->vars->move_y = d_img;
    printf("%f -- ",coodinates_converter_x(x, fract));
    printf("%f \n\n",coodinates_converter_y(y, fract));
}

int handle_mouse_input(int button, int x, int y, t_fract *fract)
{
    if (button == 5)
    {
        fract->vars->zoom++;
        if (fract->vars->zoom == 10)
            fract->vars->max_iteration += 10;
        default_zoom(fract, x, y);
        mlx_clear_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr);
        //ft_printf("%d", (int)fract->vars->zoom);
        render_fract(fract);
    }
}



static int default_dezoom(t_fract *fract, int x, int y)
{
    
}



/* 
up 126
down 125
left  123
right 124
esc 53 
+ 24 69
- 27 78
*/