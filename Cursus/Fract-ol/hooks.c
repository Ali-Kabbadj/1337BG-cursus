/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/22 06:09:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
#include <string.h>

int handle_keypress(int keycode ,t_fract *fract)
{
    if (keycode == 53)
        exit_program(fract);
    else if (keycode == 8)
    {   
        if (fract->vars.id == JULIA_ID)
            reset_julia(fract);
        else if (fract->vars.id == MANDELBROT_ID)
            reset_mandelbrot(fract);
    }
    else if (keycode == 126)
        fract->vars.move_y += fract->vars.move;
    else if (keycode == 125)
        fract->vars.move_y -= fract->vars.move;
    else if (keycode == 123)
        fract->vars.move_x += fract->vars.move;
    else if (keycode == 124)
        fract->vars.move_x -= fract->vars.move;
    else if (keycode == K_R || keycode == K_G || keycode == K_B)
        ft_move_color(fract, keycode);
    else if (keycode == 35)
    {
        if (fract->vars.pause_julia == 1)
            fract->vars.pause_julia = 0;
        else
            fract->vars.pause_julia = 1;
    }
    if (keycode == 8 || keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124 || keycode == K_R || keycode == K_G || keycode == K_B)
    {
        mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
        render_fract(fract);
    }
    return (0);
}

static long double coodinates_x(long double x , t_fract *fract)
{
    return(x * (fract->vars.complex_axis.x_end - fract->vars.complex_axis.x_start) / WIDTH + fract->vars.complex_axis.x_start);
}

static long double coodinates_y(long double y, t_fract *fract)
{
    return(fract->vars.complex_axis.y_end - (y * (fract->vars.complex_axis.y_end - fract->vars.complex_axis.y_start) / HIGHT));
}

static void zoom(t_fract *fract, int x, int y, int button)
{
    long double mouse_x;
    long double mouse_y;
    long double x_start;
    long double x_end;
    long double y_start;
    long double y_end;
    
    mouse_x = coodinates_x(x, fract);
    mouse_y = coodinates_y(y, fract);
    x_start = fract->vars.complex_axis.x_start;
    x_end = fract->vars.complex_axis.x_end;
    y_start = fract->vars.complex_axis.y_start;
    y_end = fract->vars.complex_axis.y_end;
    if (button == 5)
    {
        fract->vars.max_iteration += 10;
        fract->vars.zoom = 0.9;
        fract->vars.complex_axis.x_start = mouse_x + fract->vars.zoom * (x_start - mouse_x);
        fract->vars.complex_axis.x_end = mouse_x + fract->vars.zoom * (x_end - mouse_x);
        fract->vars.complex_axis.y_start = mouse_y + fract->vars.zoom * (y_start - mouse_y);
        fract->vars.complex_axis.y_end = mouse_y + fract->vars.zoom * (y_end - mouse_y) ;
        fract->vars.move *= fract->vars.zoom;
    }
    else if (button == 4)
    {
        fract->vars.zoom = 1.1;
        if (fract->vars.max_iteration > 50 && fract->vars.max_iteration - 10 >= 50)
        {
            fract->vars.max_iteration -= 10;
            fract->vars.move *= 1/0.9;
        }
        fract->vars.complex_axis.x_start = mouse_x + fract->vars.zoom * (x_start - mouse_x);
        fract->vars.complex_axis.x_end = mouse_x + fract->vars.zoom * (x_end - mouse_x);
        fract->vars.complex_axis.y_start = mouse_y + fract->vars.zoom * (y_start - mouse_y);
        fract->vars.complex_axis.y_end = mouse_y + fract->vars.zoom * (y_end - mouse_y);
    }
}

int handle_mouse_input(int button, int x, int y, t_fract *fract)
{
    if (button == 5 || button == 4)
    {
        zoom(fract, x, y, button);
        mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
        render_fract(fract);
    }
    return(0);
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
            render_julia(fract);
        }
    }
    return(0);
}