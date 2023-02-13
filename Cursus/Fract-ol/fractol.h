/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:44:03 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:52:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIDTH 500
# define HEIGHT 500

# include "math.h"
# include "./minilibx/mlx.h"
# include <stdlib.h>

//s_inp is the structure that contains all the input variables
// it is used to pass the input variables to the functions
//it_max is the maximum number of iterations
//pause is a variable that is used to pause the julia fractal
//color is a variable that is used to change the color of the fractal
//color_value is a variable that is used to change the color of the fractal
//zoom is a variable that is used to zoom in and out of the fractal
//x1 and y1 are variables that are used to move the fractal
typedef struct		s_input
{
	int				iteration_max;
	int				pause;
	int				color_id;
	int				color_value;
	double			zoom;
	double			move_x;
	double			move_y;
}					t_input;

//s_id is the structure that contains all the mlx variables
//bpp is the number of bits per pixel
//sizeline is the size of a line in bytes
//endian is the endian of the machine
//fract is the number of the fractal that is being used
//mlx_p is the mlx pointer
//win_p is the window pointer
//img_p is the image pointer
//tab is the array that contains the pixels of the image

typedef struct		s_mlx_var
{
	int				bpp;
	int				line_length;
	int				endian;
	int				fract;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	unsigned int	*tab;
}					t_mlx_var;

//s_var is the structure that contains all the variables that are used in the fractal
//x and y are the coordinates of the pixel
//y_max is the maximum value of y
//c_r and c_i are the real and imaginary parts of the constant c
//z_r and z_i are the real and imaginary parts of the variable z
typedef struct		s_fract_vars
{
	int				x;
	int				y;
	int				y_max;
	double			const_real;
	double			const_imag;
	double			z_real;
	double			z_imag;
}	                t_fract_vars;

typedef struct		s_fract
{
    t_mlx_var		*mlx_vars;
    t_input			*inputs;
    t_fract_vars	*vars;
}					t_fract;

t_fract	*init_mlx(void);
void		init_fract_type(char *input_name, t_fract *fract);
int				put_fract_to_image(t_fract *fract);

int		ft_strcmp(const char *s1, const char *s2);
void	bzero_tab(unsigned int *tab);
void	color_input(int key, t_input *inp);
void	color(t_mlx_var *id, t_fract_vars *var, t_input *inp, int i);
char			*ft_itoa(int n);
int		mouse_hook(int key, int x, int y, void *fract);
int		key_hook(int key, void *fract);
int			julia_hook(int x, int y, void *fract);

void		init_mandelbrot(t_fract *fract);
void	calc_mandelbrot(t_mlx_var *mlx_vars, t_fract_vars *var, t_input *inputs);

void		init_julia(t_fract *fract);
void	calc_julia(t_mlx_var *id, t_fract_vars *var, t_input *inp);

int			put_mandelbrot(t_fract *fract);
int			put_julia(t_fract *fract);
#endif