/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:59:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 10:36:20 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keycode ,t_fract *fract)
{
    printf("%d",keycode);
    if (keycode == 53 || keycode == 17)
    {
        exit_program(fract);
        return (0);
    }
    if (keycode == 8)
        reset_fract(fract);
    if (keycode == K_LEFT_ARROW || keycode == K_RIGTH_ARROW || keycode == K_UP_ARROW || keycode == K_DOWN_ARROW)
        move_fract(fract, keycode);
    else if (keycode == K_R || keycode == K_G || keycode == K_B)
        ft_move_color(fract, keycode);
    else if (keycode == K_C_CHAR)
        pause_upause(fract);
    if (keycode == K_I_CHAR || keycode == K_O_CHAR)
        controlle_iteration_nb(fract, keycode);
    mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
    render_fract(fract);
    return (0);
}

int handle_mouse_input(int button, int x, int y, t_fract *fract)
{
    if (button == 5 || button == 4)
        handle_zoom(fract, x, y, button);
    mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
    render_fract(fract);
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

