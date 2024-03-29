/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:49 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/26 21:45:36 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	render_fract(t_fract *fract)
{
	if (fract->vars.id == JULIA_ID)
		render_julia(fract);
	else if (fract->vars.id == MANDELBROT_ID)
		render_mandelbrot(fract);
	else if (fract->vars.id == BURNING_SHIP_ID)
		render_burning_ship(fract);
	else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
		render_burning_ship_julia(fract);
	else if (fract->vars.id == CUSTOM_JULIA_ID)
		render_custom_julia(fract);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 30,
			0xFFFFFF, ft_strjoin("MAX ITERATIONS : ",
				ft_itoa(fract->vars.max_iteration)));
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, 10, 60,
			0xFFFFFF, ft_strjoin("COLOR          : (",
				ft_strjoin(ft_itoa(fract->vars.colors.red), ft_strjoin(" , ",
						ft_strjoin(ft_itoa(fract->vars.colors.green),
							ft_strjoin(" , ",
								ft_strjoin(ft_itoa(fract->vars.colors.blue),ft_strjoin(",",ft_strjoin(
									ft_itoa(fract->vars.colors.transparency),",")))))))));
}

void	rerender_fract(t_fract *fract)
{
	mlx_clear_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr);
	render_fract(fract);
}

void	mlx_put_pixel_img(t_fract *fract)
{
	char	*dst;

	dst = fract->img_vars.addr + (fract->vars.win_axis.y
			* fract->img_vars.line_lenght + fract->vars.win_axis.x
			* (fract->img_vars.bpp / 8));
	*(unsigned int *)dst = fract->vars.colors.color;
}


void *iterate_multithreading(t_fract *fract)
{
    pthread_t thread[THREADS];
    t_fract fract_copy[THREADS];
    int i;
    
    i = 0;
    while (i < THREADS)
    {
        fract_copy[i] = *fract;
        fract_copy[i].vars.win_axis.x = i * (WIDTH / THREADS);
        if (fract->vars.id == JULIA_ID)
            pthread_create(&thread[i], NULL, iterate_julia, &fract_copy[i]);
        else if (fract->vars.id == MANDELBROT_ID)
            pthread_create(&thread[i], NULL, iterate_mandelbrot, &fract_copy[i]);
        else if (fract->vars.id == BURNING_SHIP_ID)
            pthread_create(&thread[i], NULL, iterate_burning_ship, &fract_copy[i]);
        else if (fract->vars.id == BURNING_SHIP_JULIA_ID)
            pthread_create(&thread[i], NULL, iterate_burning_ship_julia, &fract_copy[i]);
		else if (fract->vars.id == CUSTOM_JULIA_ID)
			pthread_create(&thread[i], NULL, iterate_custom_julia, &fract_copy[i]);
        i++;
    }
    i = 0;
    while (i < THREADS)
    {
        pthread_join(thread[i], NULL);
        i++;
    }
    mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
            fract->img_vars.img, 0, 0);
    return (0);  
}
