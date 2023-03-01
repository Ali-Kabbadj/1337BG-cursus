/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:14:41 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 15:20:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int					color;
	unsigned char		transparency;
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
	t_complexe			c;
	t_win_plane			win_axis;
	t_color				colors;
	t_complexe_plane	complex_axis;
	double				zoom;
	int					pause_julia;
	int					pause_color_cycle;
	double				move;
	int					color_turn;
	char				*name;
	int					text_color;
	double				e_z;
	int					switch_color_formula;
}						t_vars;

typedef struct s_fract
{
	t_img_data			img_vars;
	t_img_data			img;
	t_mlx_vars			mlx_vars;
	t_vars				vars;
}						t_fract;
#endif