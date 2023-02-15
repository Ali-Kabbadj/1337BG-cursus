/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:22:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/15 19:06:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"
# include <math.h>
# include <stdlib.h>

# define WIDTH 1000
# define HIGHT 1000

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
    double      z_real;
    double      z_imag;
}               t_complexe;

typedef struct s_vars
{
	int			id;
	int			x;
	int			y;
	double			move_x;
	double			move_y;
	int			color;
	int			max_iteration;
	int			iterations;
	t_complexe	z;
	t_complexe	c;
	double re_end;
	double re_start;
	double imag_end;
	double imag_start; 
}				t_vars;

typedef struct s_fract
{
	t_img_data	*img_vars;
	t_mlx_vars	*mlx_vars;
	t_vars		*vars;
}				t_fract;


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
void			init_hooks(t_fract *fract);

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
void render_mandelbrot(t_fract *fract);
void iterate_mandelbrot(t_fract *fract);
void init_mandelbrot(t_fract *fract);
#endif
