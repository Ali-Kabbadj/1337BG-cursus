/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractmacros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:25:59 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 09:03:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTMACROS_H
# define FRACTMACROS_H

# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000
# define SIDEBAR_WIDTH 300
# define SIDEBAR_HEIGHT 1000
# define IMAGE_WIDTH 1000
# define IMAGE_HIGHT 1000

# define NO_ERROR 0
# define NO_ARGS_ERROR -1
# define WRONG_FRACT_NAME -2
# define WRONG_NAME_MSSG "Something wrong with the fractal name!"

# define JULIA_ID 1
# define MANDELBROT_ID 2
# define BURNING_SHIP_ID 3
# define BURNING_SHIP_JULIA_ID 4
# define CUSTOM_JULIA_ID 5

# define JULIA_X_START -2
# define JULIA_X_END 2
# define JULIA_Y_START -1.5
# define JULIA_Y_END 1.5

# define MANDELBROT_X_START -2.5
# define MANDELBROT_X_END 1.5
# define MANDELBROT_Y_START -2
# define MANDELBROT_Y_END 2

# define BURNING_SHIP_X_START 1.5
# define BURNING_SHIP_X_END -2
# define BURNING_SHIP_Y_START 1
# define BURNING_SHIP_Y_END -2

# define CUSTOM_JULIA_X_START -2.5
# define CUSTOM_JULIA_X_END 2.5
# define CUSTOM_JULIA_Y_START -2
# define CUSTOM_JULIA_Y_END 2

# define MOUSE_SCROLL_DOWN 4
# define MOUSE_SCROLL_UP 5

# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125

# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_PLUS 24
# define K_MINUS 27

# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_5 23
# define K_6 22
# define K_7 26
# define K_8 28

# define K_ESC 53
# define K_SPACEBAR 49

# define K_H 4
# define K_A 0
# define K_R 15
# define K_G 5
# define K_B 11
# define K_P 35
# define K_L 37
# define K_I 34
# define K_O 31
# define K_C 8
# define K_T 17
# define K_S 1
# define K_D 2
# define K_F 3
# define K_Q 12

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000

# define ZOOM_IN 0.9
# define ZOOM_OUT 1.1
# define EXP 2.718
#endif 