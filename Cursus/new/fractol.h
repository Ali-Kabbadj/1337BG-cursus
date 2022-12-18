#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 1000
# define WIN_HIGHT 1000
# define WIN_TITLE "fract-ol"
typedef struct s_data
{
	void	*img;
	char	*adresse;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	canva;
	int win_width;
	int win_hight;
}			t_fractal;

/*Initilizer*/
void init_hooks(t_fractal *fract);
int			init_window(t_fractal *fract, int width, int height,
				char *title);
int			init_mlx(t_fractal *fract);
int			init_fractal(t_fractal *fract, int width, int height,
				char *win_title);
void	init_img(t_fractal *fract);

/*hooks*/
int close_program(void *param);
int handle_keypress(int keycode,void *vars);

/*Renderer*/
void put_pixel(t_data *canva, int x, int y, int color);
void render_background(t_fractal *fract, int color);

#endif