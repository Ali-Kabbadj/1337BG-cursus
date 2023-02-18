/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/18 16:45:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	one_time_init(t_fract *fract)
{
	fract->vars->zoom = 0.7;
	fract->vars->max_iteration = 50;
	fract->vars->re_start = -2;
	fract->vars->re_end = 2;
	fract->vars->imag_start = -2;
	fract->vars->imag_end = 2;
	fract->vars->zoom_in = 0;
	fract->vars->move_x = 0;
	fract->vars->move_y = 0;
	fract->vars->zoom_in = 0;
	fract->vars->red = 9;
	fract->vars->green = 9;
	fract->vars->blue = 25;
}


void			ft_move_color(t_fract *fract, int key)
{
	if (key == K_R)
		fract->vars->red++;
	if (key == K_G)
		fract->vars->green++;
	if (key == K_B)
		fract->vars->blue++;
}


void	init_mandelbrot(t_fract *fract)
{
	fract->vars->z.z_real = 0;
	fract->vars->z.z_imag = 0;
}

float	coodinates_converter_x(float x, t_fract *fract)
{
	return (x * (fract->vars->re_end - fract->vars->re_start) / WIDTH
		+ fract->vars->re_start + fract->vars->move_x);
}

float	coodinates_converter_y(float y, t_fract *fract)
{
	return (fract->vars->imag_end - (y * (fract->vars->imag_end
				- fract->vars->imag_start) / HIGHT + fract->vars->move_y));
}


void	iterate_mandelbrot(t_fract *fract)
{
	int		i;
	float	a;
	int		cnt;
	int		max_cnt;
	double		k;

	// float tmp_re;
	i = 0;
	a = 0;
	// tmp_re = 0;
	// fract->vars->x_re = coodinates_converter_x(fract->vars->x, fract);
	// fract->vars->x_img = coodinates_converter_y(fract->vars->y, fract);
	// while (i < fract->vars->max_iteration)
	// {
	//     tmp_re = fract->vars->z.z_real;
	//     fract->vars->z.z_real = tmp_re * tmp_re - fract->vars->z.z_imag
	//	* fract->vars->z.z_imag + fract->vars->x_re;
	//     fract->vars->z.z_imag = 2 * tmp_re * fract->vars->z.z_imag
	//	+ fract->vars->x_img;
	//     printf("%f\n", (2 * fabs(fract->vars->z.z_real)
	//			* log(fabs(fract->vars->z.z_real)) ) / (tmp_re * tmp_re
	//			- fract->vars->z.z_imag * fract->vars->z.z_imag));
	//     printf("%f\n\n\n", (2 * fabs(fract->vars->z.z_imag)
				// * log(fabs(fract->vars->z.z_imag)) ) / (2 * tmp_re
				// * fract->vars->z.z_imag + fract->vars->x_img));
	//     if (fract->vars->z.z_real * fract->vars->z.z_real
			// + fract->vars->z.z_imag * fract->vars->z.z_imag > 4)
	//         break ;
	//     i++;
	// }
	// if (i ==fract->vars->max_iteration )
	//     fract->vars->color = 0x000000;
	// else
	//     fract->vars->color = 0xFFFFFF;
	t_complexe  z, z_new, dz, dz_new;
	cnt = 1;
	max_cnt = 100;
	fract->vars->x_re = coodinates_converter_x(fract->vars->x, fract);
	fract->vars->x_img = coodinates_converter_y(fract->vars->y, fract);
	// c.z_real = coodinates_converter_x(fract->vars->x, fract);
	// c.z_imag = coodinates_converter_y(fract->vars->y, fract);
	z.z_real = 0;
	z.z_imag = 0;
	dz.z_real = 1;
	dz.z_imag = 0;
	while (cnt < fract->vars->max_iteration)
	{
		z_new.z_real = z.z_real * z.z_real - z.z_imag * z.z_imag + fract->vars->x_re;
		z_new.z_imag = 2 * z.z_real * z.z_imag + fract->vars->x_img;
		dz_new.z_real = 2 * (z.z_real * dz.z_real - z.z_imag * dz.z_imag) + 1;
		dz_new.z_imag = 2 * (z.z_real * dz.z_imag * dz.z_real * z.z_imag) + 1;
		z.z_real = z_new.z_real;
		z.z_imag = z_new.z_imag;
		dz.z_real = dz_new.z_real;
		dz.z_imag = dz_new.z_imag;
		if (z.z_real * z.z_real + z.z_imag * z.z_imag > 4)
			break ;
		cnt++;
	}
	//a = ( sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag) * log(sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag)) ) / sqrt(dz.z_real * dz.z_real + dz.z_imag * dz.z_imag);
	k = cnt * log(2);
	if (cnt != fract->vars->max_iteration)
		fract->vars->color = (int)(fract->vars->red * k) | (int)(fract->vars->green * k) << 8 |
			(int)(fract->vars->blue * k) << 16;
	else
		fract->vars->color = 0x000000;
	
}

int	render_mandelbrot(t_fract *fract)
{
	fract->vars->x = 0;
	while (fract->vars->x < WIDTH)
	{
		fract->vars->y = 0;
		while (fract->vars->y < HIGHT)
		{
			init_mandelbrot(fract);
			iterate_mandelbrot(fract);
			mlx_put_pixel_img(fract);
			fract->vars->y++;
		}
		fract->vars->x++;
	}
	mlx_put_image_to_window(fract->mlx_vars->mlx_ptr, fract->mlx_vars->win_ptr,
			fract->img_vars->img, 0, 0);
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