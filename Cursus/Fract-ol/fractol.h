/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:22:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/18 16:36:14 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"
# include <math.h>
# include <stdlib.h>
#include <stdio.h>
# include <pthread.h>

# define WIDTH 1000
# define HIGHT 1000

# define THREADS_AMOUNT 4
# define K_MOUSE_LEFT 1
# define K_MOUSE_RIGHT 2
# define K_MOUSE_WHEEL_DOWN 4
# define K_MOUSE_WHEEL_UP 5
# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_0 82

# define K_NUM_7 89
# define K_NUM_4 86
# define K_NUM_8 91
# define K_NUM_6 88
# define K_NUM_2 84
# define K_NUM_9 92
# define K_NUM_3 85
# define K_NUM_1 83

# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_5 23
# define K_6 22
# define K_7 26
# define K_8 28

# define FR_MANDELBROT K_1
# define FR_JULIA K_2
# define FR_BSHIP K_3
# define FR_SPINNER K_4
# define FR_FISH K_5
# define FR_FLOWER K_6
# define FR_HEART K_7
# define FR_SPLASH K_8

# define K_ESC 53
# define K_SPACEBAR 49
# define K_H 4
# define K_R 15
# define K_G 5
# define K_B 11
# define K_L 37
# define K_I 34

# define C_RED 0xFF0000
# define C_GREEN 0x00FF00
# define C_BLUE 0x0000FF
# define C_WHITE 0xFFFFFF
# define C_YELLOW 0xD8CE0F

# define JULIA_ID 1
# define MANDELBROT_ID 2

# define JULIA_WIN_NAME "Fract-ol : Julia"
# define MANDELBROT_WIN_NAME "Fract-ol : Mandelbrot"

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_img_data;

typedef struct s_mlx_vars
{
	void		*win_ptr;
	void		*mlx_ptr;
}				t_mlx_vars;

typedef struct s_complexe
{
    float      z_real;
    float      z_imag;
}               t_complexe;

typedef struct s_vars
{
	int			id;
	int			x;
	int			y;
	float			move_x;
	float			move_y;
	int			color;
	int			max_iteration;
	int			iterations;
	t_complexe	z;
	t_complexe	c;
	float re_end;
	float re_start;
	float imag_end;
	float imag_start; 
	float zoom;
	float x_re;
	float x_img;
	int fist_init;
	int zoom_in;
	int			col_offset;
	int			red;
	int			green;
	int			blue;
	
}				t_vars;

typedef struct s_fract
{
	t_img_data	*img_vars;
	t_mlx_vars	*mlx_vars;
	t_vars		*vars;
}				t_fract;


/*Hooks*/
int handle_keypress(int keycode ,t_fract *fract);
int handle_mouse_input(int button, int x, int y, t_fract *fract);

/* complexe z*/
double add_real(t_complexe *z1, t_complexe *z2);
double add_imag(t_complexe *z1, t_complexe *z2);
double multiply_real(t_complexe *z1, t_complexe *z2);
double multiply_imag(t_complexe *z1, t_complexe *z2);
double squared_modulus(t_complexe *z);

/* initializer */
void			init_mlx_vars(t_fract *fract);
void			init_fract_type(t_fract *fract, char *name);
void			init_img(t_fract *fract);
void			init_structs(t_fract *fract);
int			init_hooks(t_fract *fract);
void one_time_init(t_fract *fract);

/* utiles */
int				ft_strcmp(const char *s1, const char *s2);
char			*get_win_title(t_fract *fract);
void			exit_program(t_fract *fract);
void			dispose_mlx_vars(t_fract *fract);

/* mlx */
void			mlx_put_pixel_img(t_fract *fract);

/* renderer */
void			render_fract(t_fract *fract);

/* mandelbrot*/
int render_mandelbrot(t_fract *fract);
void iterate_mandelbrot(t_fract *fract);
void init_mandelbrot(t_fract *fract);
float coodinates_converter_x(float x , t_fract *fract);
float coodinates_converter_y(float y, t_fract *fract);
void			ft_move_color(t_fract *fract, int key);

#endif
