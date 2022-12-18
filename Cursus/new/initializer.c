#include "fractol.h"

void    init_img(t_fractal *fract)
{
	fract->canva.img = mlx_new_image(fract->mlx_ptr, WIN_WIDTH, WIN_HIGHT);
	fract->canva.adresse = mlx_get_data_addr(fract->canva.img,
			&fract->canva.bpp, &fract->canva.line_length, &fract->canva.endian);
}

void	init_hooks(t_fractal *fract)
{
	mlx_key_hook(fract->win_ptr, handle_keypress, fract);
	mlx_hook(fract->win_ptr, 17, 1L << 17, close_program, fract);
}

int	init_window(t_fractal *fract, int width, int height, char *title)
{
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, width, height, title);
	if (fract->win_ptr == NULL)
		return (1);
	fract->win_hight = WIN_HIGHT;
	fract->win_width = WIN_WIDTH;
	return (0);
}

int	init_mlx(t_fractal *fract)
{
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
		return (1);
	return (0);
}

int	init_fractal(t_fractal *fract, int width, int height, char *win_title)
{
	if (init_mlx(fract) || init_window(fract, width, height, win_title))
		return (1);
	return (0);
}