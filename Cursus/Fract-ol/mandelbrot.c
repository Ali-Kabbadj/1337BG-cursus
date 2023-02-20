/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/20 04:28:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fract *fract)
{
	fract->vars.zoom = 0.7;
	fract->vars.max_iteration = 50;
	fract->vars.complex_axis.x_start = -2;
	fract->vars.complex_axis.x_end = 2;
	fract->vars.complex_axis.y_start = -2;
	fract->vars.complex_axis.y_end = 2;
	fract->vars.zoom_in = 0;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.zoom_in = 0;
	fract->vars.colors.red = 9;
	fract->vars.colors.green = 9;
	fract->vars.colors.blue = 25;
	fract->vars.iterations = 0;
}

static void mandelbrot_formula(t_complexe *z, t_complexe c)
{
	float tmp_z_re;
	
	tmp_z_re = z->real;
	z->real = z->real * z->real - z->imag * z->imag + c.real;
	z->imag = 2 * tmp_z_re * z->imag + c.imag;
}

void	iterate_mandelbrot(t_fract *fract)
{
	fract->vars.c.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
	fract->vars.c.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
	fract->vars.z.real = 0;
	fract->vars.z.imag = 0;
	while (fract->vars.iterations < fract->vars.max_iteration)
	{
		mandelbrot_formula(&fract->vars.z, fract->vars.c);
		if (sqrt_root_modulus(fract->vars.z) > 4)
			break ;
		fract->vars.iterations++;
	}
	set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
	fract->vars.iterations = 0;
}

int	render_mandelbrot(t_fract *fract)
{
	fract->vars.win_axis.x = 0;
	while (fract->vars.win_axis.x < WIDTH)
	{
		fract->vars.win_axis.y = 0;
		while (fract->vars.win_axis.y < HIGHT)
		{
			iterate_mandelbrot(fract);
			mlx_put_pixel_img(fract);
			fract->vars.win_axis.y++;
		}
		fract->vars.win_axis.x++;
	}
	mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
			fract->img_vars.img, 0, 0);
	return (0);
}

// void			ft_pthread_mandelbrot(t_win *win)
// {
// 	pthread_t	pt[THREADS_AMOUNT];
// 	t_win		w[THREADS_AMOUNT];
// 	int			i;

// 	win->dx = (win->max_val.x - win->min_val.x) / (WIDTH);
// 	win->dy = (win->max_val.y - win->min_val.y) / (HEIGHT);
// 	i = 0;
// 	while (i < THREADS_AMOUNT - 1)
// 	{
// 		ft_memcpy((void*)&w[i], (void*)win, sizeof(t_win));
// 		w[i].j = (HEIGHT / THREADS_AMOUNT) * i;
// 		w[i].j_max = (HEIGHT / THREADS_AMOUNT) * (i + 1);
// 		i++;
// 	}
// 	ft_memcpy((void*)&w[i], (void*)win, sizeof(t_win));
// 	w[i].j = (HEIGHT / THREADS_AMOUNT) * i;
// 	w[i].j_max = HEIGHT;
// 	i = -1;
// 	while (++i < THREADS_AMOUNT)
// 		pthread_create((pt + i), NULL, ft_mandelbrot, (void*)(w + i));
// 	i = -1;
// 	while (++i < THREADS_AMOUNT)
// 		pthread_join(pt[i], NULL);
// }