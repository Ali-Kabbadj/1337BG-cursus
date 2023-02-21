/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/21 00:24:11 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keycode ,t_fract *fract)
{
    if (keycode == 53)
        exit_program(fract);
    else if (keycode == 126)
        fract->vars.move_y += 0.09;
    else if (keycode == 125)
        fract->vars.move_y -= 0.09;
    else if (keycode == 123)
        fract->vars.move_x += 0.09;
    else if (keycode == 124)
        fract->vars.move_x -= 0.09;
    else if (keycode == K_R || keycode == K_G || keycode == K_B)
        ft_move_color(fract, keycode);
    else if (keycode == 35)
    {
        if (fract->vars.pause_julia == 1)
            fract->vars.pause_julia = 0;
        else
            fract->vars.pause_julia = 1;
    }
    if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124 || keycode == K_R || keycode == K_G || keycode == K_B)
    {
        mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
        render_fract(fract);
    }
    return (0);
}

static float coodinates_x(float x , t_fract *fract)
{
    return(x * (fract->vars.complex_axis.x_end - fract->vars.complex_axis.x_start) / WIDTH + fract->vars.complex_axis.x_start);
}

static float coodinates_y(float y, t_fract *fract)
{
    return(fract->vars.complex_axis.y_end - (y * (fract->vars.complex_axis.y_end - fract->vars.complex_axis.y_start) / HIGHT));
}


static int default_zoom(t_fract *fract , int x, int y, int button)
{
    float d_re;
    float d_img;
    float s_re;
    float s_img;
    float old_re_start;
    float old_re_end;
    float old_img_start;
    float old_img_end;

    old_re_start = fract->vars.complex_axis.x_start;
    old_re_end = fract->vars.complex_axis.x_end;
    old_img_start = fract->vars.complex_axis.y_start;
    old_img_end = fract->vars.complex_axis.y_end;
    if (button == 5)
    {
        fract->vars.max_iteration += 50; 
        fract->vars.zoom_in++;
        d_re = fract->vars.zoom * (fract->vars.complex_axis.x_end - coodinates_x(x , fract));
        d_img = fract->vars.zoom * (fract->vars.complex_axis.y_end - coodinates_y(y, fract));
        s_re = (fract->vars.complex_axis.x_end - fract->vars.complex_axis.x_start) * fract->vars.zoom;
        s_img = (fract->vars.complex_axis.y_end - fract->vars.complex_axis.y_start) * fract->vars.zoom;
        fract->vars.complex_axis.x_end = coodinates_x(x, fract) + d_re;
        fract->vars.complex_axis.y_end = coodinates_y(y, fract) + d_img;
        fract->vars.complex_axis.x_start = fract->vars.complex_axis.x_end - s_re;
        fract->vars.complex_axis.y_start = fract->vars.complex_axis.y_end - s_img;
    }else if (button == 4)
    {
        if (fract->vars.max_iteration > 50)
            if (fract->vars.zoom_in % 10 == 0)
            {
                fract->vars.max_iteration -= 100; 
                fract->vars.zoom_in--;
            }
        if (fract->vars.max_iteration < 50)
            fract->vars.max_iteration = 50;
        d_re = (1/fract->vars.zoom) * (fract->vars.complex_axis.x_end - coodinates_x(x , fract));
        d_img = (1/fract->vars.zoom) * (fract->vars.complex_axis.y_end - coodinates_y(y, fract));
        s_re = (fract->vars.complex_axis.x_end - fract->vars.complex_axis.x_start) * (1/fract->vars.zoom);
        s_img =  (fract->vars.complex_axis.y_end - fract->vars.complex_axis.y_start) * (1/fract->vars.zoom);
        fract->vars.complex_axis.x_end = coodinates_x(x, fract) + d_re;
        fract->vars.complex_axis.y_end = coodinates_y(y, fract) + d_img;
        fract->vars.complex_axis.x_start = fract->vars.complex_axis.x_end - s_re;
        fract->vars.complex_axis.y_start = fract->vars.complex_axis.y_end - s_img;
    }
    
}


int handle_mouse_input(int button, int x, int y, t_fract *fract)
{
    if (button == 5 || button == 4)
    {
        default_zoom(fract, x, y, button);
        mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
        render_fract(fract);
    }
}

int julia_hook(t_fract *fract)
{
    int x, y;
    
    x = 0;
    y = 0;
    if (fract->vars.pause_julia == 0)
    {
        mlx_mouse_get_pos(fract->mlx_vars.win_ptr, &x, &y);
        if (x < WIDTH && y < HIGHT)
        {
            fract->vars.c.real = coodinates_converter_x(x, fract);
            fract->vars.c.imag = coodinates_converter_y(y, fract);
            mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
            pthread_julia(fract);
        }
    }
    return(0);
}