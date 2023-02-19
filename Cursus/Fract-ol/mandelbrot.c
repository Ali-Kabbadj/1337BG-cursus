/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/19 01:19:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	one_time_init_mandelbrot(t_fract *fract)
{
	fract->vars->zoom = 0.7;
	fract->vars->max_iteration = 100;
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
	fract->vars->smoothing = 0;
}


void	init_mandelbrot(t_fract *fract)
{
	fract->vars->z.z_real = 0;
	fract->vars->z.z_imag = 0;
}


void set_pixel_color(t_fract *fract, int iterations, t_complexe z)
{
	double		k;
	float ni;
	float na;
	
	//ni = iterations + ((log(log(2)) - log(log(sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag)))))/(log(fract->vars->smoothing));
	//ni = iterations + ((log(log(2)) - log(log(sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag)))))/(log(2));
	//ni = iterations + ((log2(log2(2)) - log2(log2(sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag)))))/(log2(fract->vars->smoothing));
	//ni = iterations + (log2(log2(4)) - log(log(z.z_real * z.z_real + z.z_imag * z.z_imag))) / log2(a);
	//ni = a;
	ni = iterations  + (((log(log(2)) - log(log(z.z_real * z.z_real + z.z_imag * z.z_imag))) / log(2)));
	//ni  = log(log(2)) / log(z.z_real * z.z_real + z.z_imag * z.z_imag) / log(pow(2.718 , z.z_real * z.z_real + z.z_imag * z.z_imag) * - 1);
	//printf("%f - \n ",ni);
	//printf("%f\n\n\n", ni);
	//k  = iterations * a;   
	// if (iterations != fract->vars->max_iteration)
	// 	fract->vars->color = (int)(fract->vars->red * k) | (int)(fract->vars->green * k) << 8 |
	// 		(int)(fract->vars->blue * k) << 16;
	//ni = a;
	if (iterations != fract->vars->max_iteration)
		fract->vars->color = (int)(fract->vars->red * ni) | (int)(fract->vars->green * ni) << 8 |
			(int)(fract->vars->blue * ni) << 16;
	else
		fract->vars->color = 0x000000;
}

void	iterate_mandelbrot(t_fract *fract)
{
	int		i;
	float	a;
	int		iterations ;
	float	e;

	i = 0;
	a = 0;
	e = 2.718;
	t_complexe  z, z_new, dz, dz_new;
	iterations = 1;
	fract->vars->x_re = coodinates_converter_x(fract->vars->x, fract);
	fract->vars->x_img = coodinates_converter_y(fract->vars->y, fract);
	z.z_real = 0;
	z.z_imag = 0;
	dz.z_real = 1;
	dz.z_imag = 0;
	//fract->vars->smoothing = 0;
	while (iterations < fract->vars->max_iteration)
	{
		z_new.z_real = z.z_real * z.z_real - z.z_imag * z.z_imag + fract->vars->x_re;
		z_new.z_imag = 2 * z.z_real * z.z_imag + fract->vars->x_img;
		dz_new.z_real = 2 * (z.z_real * dz.z_real - z.z_imag * dz.z_imag) + 1;
		dz_new.z_imag = 2 * (z.z_real * dz.z_imag * dz.z_real * z.z_imag) + 1;
		z.z_real = z_new.z_real;
		z.z_imag = z_new.z_imag;
		dz.z_real = dz_new.z_real;
		dz.z_imag = dz_new.z_imag;	
		//fract->vars->smoothing += pow(e, sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag) * -1);
		//printf("%f\n",fract->vars->smoothing);
		if (z.z_real * z.z_real + z.z_imag * z.z_imag > 4)
			break ;
		
		iterations++;
	}
	//a = ( sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag) * log(sqrt(z.z_real * z.z_real + z.z_imag * z.z_imag)) ) / sqrt(dz.z_real * dz.z_real + dz.z_imag * dz.z_imag);
	//a = iterations + 2 - log((log(z.z_real * z.z_real + z.z_imag * z.z_imag)/fract->vars->smoothing));
	//a = log(z.z_real * z.z_real + z.z_imag * z.z_imag) / pow(2, iterations);
	set_pixel_color(fract, iterations, z);
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