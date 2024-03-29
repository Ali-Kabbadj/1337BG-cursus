/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:22:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/27 00:23:59 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1000
# define HIGHT 1000
# define THREADS 20

/*errors*/
# define NO_ERROR 0
# define NO_ARGS_ERROR -1
# define WRONG_FRACT_NAME -2

/* error messages*/
# define WRONG_NAME_MSSG "It appears that there is something wrong with the fractal name!"

/*fractals default start and end values*/
# define JULIA_X_START -2
# define JULIA_X_END 2
# define JULIA_Y_START -1.5
# define JULIA_Y_END 1.5

# define MANDELBROT_X_START -2
# define MANDELBROT_X_END 2
# define MANDELBROT_Y_START -2
# define MANDELBROT_Y_END 2

# define BURNING_SHIP_X_START -1.5;
# define BURNING_SHIP_X_END 2;
# define BURNING_SHIP_Y_START -1;
# define BURNING_SHIP_Y_END 2;

# define BURNING_SHIP_JULIA_X_START -2;
# define BURNING_SHIP_JULIA_X_END 2;
# define BURNING_SHIP_JULIA_Y_START -1.5;
# define BURNING_SHIP_JULIA_Y_END 1.5;

# define CUSTOM_JULIA_X_START -2.5;
# define CUSTOM_JULIA_X_END 2.5;
# define CUSTOM_JULIA_Y_START -2;
# define CUSTOM_JULIA_Y_END 2;

/*keys*/
# define K_MOUSE_LEFT 1
# define K_MOUSE_RIGHT 2
# define K_MOUSE_WHEEL_DOWN 4
# define K_MOUSE_WHEEL_UP 5

# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125

# define K_P 35
# define K_L 37
# define K_I 34
# define K_O 31
# define K_C 8

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

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
# define K_T 17

# define C_RED 0xAA0000
# define C_GREEN 0x00AA00
# define C_BLUE 0x0000AA
# define C_WHITE 0xFFFFFF
# define C_YELLOW 0xD8CE0F

# define JULIA_ID 1
# define MANDELBROT_ID 2
# define BURNING_SHIP_ID 3
# define BURNING_SHIP_JULIA_ID 4
# define CUSTOM_JULIA_ID 5

# define JULIA_WIN_NAME "Fract-ol : Julia"
# define MANDELBROT_WIN_NAME "Fract-ol : Mandelbrot"
# define BURNING_SHIP_WIN_NAME "Fract-ol : Burning Ship"
# define BURNING_SHIP_JULIA_WIN_NAME "Fract-ol : Burning Ship Julia"
# define CUSTOM_JULIA_WIN_NAME "Fract-ol : Custom Julia"

typedef struct s_img_data
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_lenght;
	int					endian;
}						t_img_data;

typedef struct s_mlx_vars
{
	void				*win_ptr;
	void				*mlx_ptr;
}						t_mlx_vars;

typedef struct s_complexe
{
	double				real;
	double				imag;
}						t_complexe;

typedef struct s_win_plane
{
	int					x;
	int					y;
}						t_win_plane;

typedef struct s_complex_plane
{
	double				x_re;
	double				y_imag;
	double				x_end;
	double				x_start;
	double				y_end;
	double				y_start;
}						t_complexe_plane;

typedef struct s_color
{
	unsigned int					color;
	unsigned int		transparency;
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}						t_color;

typedef struct s_vars
{
	int					id;
	double				move_x;
	double				move_y;
	int					max_iteration;
	int					iterations;
	t_complexe			z;
	t_complexe			z_start;
	t_complexe			c;
	t_win_plane			win_axis;
	t_color				colors;
	t_complexe_plane	complex_axis;
	double				zoom;
	int					pause_julia;
	int					pause_color_cycle;
	double				move;
	int					color_turn;

}						t_vars;

typedef struct s_fract
{
	t_img_data			img_vars;
	t_mlx_vars			mlx_vars;
	t_vars				vars;
}						t_fract;

/*julia*/
void						render_julia(t_fract *fract);
void *iterate_julia(void *param);

/*mandelbrot*/
void						render_mandelbrot(t_fract *fract);
void	*iterate_mandelbrot(void *param);

/*burning ship*/
void						render_burning_ship(t_fract *fract);
void *iterate_burning_ship(void *param);

/*burning ship julia*/
void						render_burning_ship_julia(t_fract *fract);
void *iterate_burning_ship_julia(void *fract);

/*custom julia*/
void						render_custom_julia(t_fract *fract);
void	*iterate_custom_julia(void *param);

/*initilizer*/
void					init_fract_type(t_fract *fract, char *name);
void					init_img(t_fract *fract);
void					init_mlx_vars(t_fract *fract);
int						init_hooks(t_fract *fract);
void					init_vars(t_fract *fract);

/*zoom*/
void					handle_zoom(t_fract *fract, int x, int y, int button);

/*hooks*/
int						handle_keypress(int keycode, t_fract *fract);
int						handle_mouse_input(int button, int x, int y,
							t_fract *fract);
int						loop_hook(t_fract *fract);

/*hooks helpers*/
void					controlle_iteration_nb(t_fract *fract, int keycode);
void					move_fract(t_fract *fract, int keycode);
void					pause_upause(t_fract *fract, int keycode);

/*utiles*/
int						exit_program(t_fract *fract);
char					*get_win_title(t_fract *fract);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strcmp(const char *s1, const char *s2);

/*utiles 2*/
void					default_fract(t_fract *fract);

/*utiles 3*/
double					coodinates_converter_x(double x, t_fract *fract);
double					coodinates_converter_y(double y, t_fract *fract);
void					ft_move_color(t_fract *fract, int key);
void					set_pixel_color(t_fract *fract, int iterations,
							t_complexe z);

/*renderer*/
void					render_fract(t_fract *fract);
void					rerender_fract(t_fract *fract);
void					mlx_put_pixel_img(t_fract *fract);
void					*iterate_multithreading(t_fract *fract);

/*input handler*/
void					handle_input(int ac, char **cmd_input, t_fract *fract);

/*formulas*/
void					mandelbrot_julia_formula(t_complexe *z, t_complexe c);
void					burning_ship_julia_formula(t_complexe *z, t_complexe c);
void					burning_ship_formula(t_complexe *z,t_fract *fract);
void					custom_julia_formula(t_complexe *z, t_complexe c);
double					absolute_value(t_complexe z);
#endif
