/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/21 11:23:49 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
#include <string.h>

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

//clear mlx memory and data and create a new window with the old data
static void reset(t_fract *fract)
{
    //t_fract *new_fract;
    
    mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
    mlx_destroy_image(fract->mlx_vars.mlx_ptr, fract->img_vars.img);
    
    // new_fract = malloc(sizeof(t_fract));
    
    // memcpy((void *)new_fract, (void *)fract, sizeof(t_fract ));
    
   // new_fract->img_vars.img = mlx_new_image(new_fract->mlx_vars.mlx_ptr, WIDTH, HIGHT);
    //new_fract->img_vars.addr = mlx_get_data_addr(new_fract->img_vars.img, &new_fract->img_vars.bpp, &new_fract->img_vars.line_lenght, &new_fract->img_vars.endian);
    
    
	init_img(fract);
    //copy the old data to the new struct using memcpy
    //free(fract);
    //retreive the old data from the old struct
    render_fract(fract);
}


// zoom indefinitly where the mouse is in 2D
static void zoom(t_fract *fract, int x, int y, int button)
{
    float zoom_factor;
    float mouse_x;
    float mouse_y;
    float x_start;
    float x_end;
    float y_start;
    float y_end;
    mouse_x = coodinates_x(x, fract) ;
    mouse_y = coodinates_y(y, fract);
    x_start = fract->vars.complex_axis.x_start;
    x_end = fract->vars.complex_axis.x_end;
    y_start = fract->vars.complex_axis.y_start;
    y_end = fract->vars.complex_axis.y_end;
    if (button == 5)
    {
        fract->vars.max_iteration += 100;
        zoom_factor = 0.9;
        
        fract->vars.complex_axis.x_start = mouse_x + zoom_factor * (x_start - mouse_x);
        fract->vars.complex_axis.x_end = mouse_x + zoom_factor * (x_end - mouse_x);
        fract->vars.complex_axis.y_start = mouse_y + zoom_factor * (y_start - mouse_y);
        fract->vars.complex_axis.y_end = mouse_y + zoom_factor * (y_end - mouse_y) ;
        
        render_fract(fract);
    }
    else if (button == 4)
    {
        zoom_factor = 1.1;
        fract->vars.complex_axis.x_start = mouse_x + zoom_factor * (x_start - mouse_x);
        fract->vars.complex_axis.x_end = mouse_x + zoom_factor * (x_end - mouse_x);
        fract->vars.complex_axis.y_start = mouse_y + zoom_factor * (y_start - mouse_y);
        fract->vars.complex_axis.y_end = mouse_y + zoom_factor * (y_end - mouse_y);
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