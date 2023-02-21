/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/21 00:52:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_fract *fract)
{
    fract->vars.zoom = 0.7;
	fract->vars.max_iteration = 50;
	fract->vars.complex_axis.x_start = -2;
	fract->vars.complex_axis.x_end = 2;
	fract->vars.complex_axis.y_start = -1.5;
	fract->vars.complex_axis.y_end = 1.5;
	fract->vars.zoom_in = 0;
	fract->vars.move_x = 0;
	fract->vars.move_y = 0;
	fract->vars.zoom_in = 0;
	fract->vars.colors.red = 11;
	fract->vars.colors.green = 12;
	fract->vars.colors.blue = 27;
    fract->vars.pause_julia = 0;
    fract->vars.c.real = -0.7;
    fract->vars.c.imag = -0.27015;
    fract->vars.iterations = 0;
}

static void julia_formula(t_complexe *z, t_complexe c)
{
    double tmp_z_re;
    
    tmp_z_re = z->real;
    z->real = z->real * z->real - z->imag * z->imag + c.real;
    z->imag = 2 * tmp_z_re * z->imag + c.imag;
}


// t_fract *rerender(t_fract *fract)
// {
//     t_fract *new_fract;

//     new_fract = malloc(sizeof(t_fract));
    
//     new_fract->vars.zoom = fract->vars.zoom;
// 	new_fract->vars.max_iteration = fract->vars.max_iteration;
// 	new_fract->vars.complex_axis.x_start = fract->vars.complex_axis.x_start;
// 	new_fract->vars.complex_axis.x_end = fract->vars.complex_axis.x_end;
// 	new_fract->vars.complex_axis.y_start = fract->vars.complex_axis.y_start;
// 	new_fract->vars.complex_axis.y_end = fract->vars.complex_axis.y_end;
// 	new_fract->vars.zoom_in = fract->vars.zoom_in;
// 	new_fract->vars.move_x = fract->vars.move_x;
// 	new_fract->vars.move_y = fract->vars.move_y;
// 	new_fract->vars.zoom_in = fract->vars.zoom_in;
// 	new_fract->vars.colors.red = fract->vars.colors.red;
// 	new_fract->vars.colors.green = fract->vars.colors.green;
// 	new_fract->vars.colors.blue = fract->vars.colors.blue;
//     new_fract->vars.pause_julia = fract->vars.pause_julia;
//     new_fract->vars.c.real = fract->vars.c.real;
//     new_fract->vars.c.imag = fract->vars.c.imag;
//     new_fract->vars.iterations = fract->vars.iterations;
//     mlx_clear_window(fract->mlx_vars.win_ptr, fract->mlx_vars.win_ptr);
//     mlx_destroy_image(fract->mlx_vars.mlx_ptr, fract->img_vars.img);
// 	init_img(new_fract);
//     return(new_fract);
// }

// int render_julia(t_fract *fract)
// {
//     fract->vars.win_axis.x = 0;
//     while (fract->vars.win_axis.x < WIDTH)
//     {
//         fract->vars.win_axis.y = 0;
//         while (fract->vars.win_axis.y < HIGHT)
//         {
//             iterate_julia(fract);
//             mlx_put_pixel_img(fract);
//             fract->vars.win_axis.y++;
//         }
//         fract->vars.win_axis.x++;
//     }
//     mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
// 			fract->img_vars.img, 0, 0);
//     return (0);
// }

void iterate_julia(void *param)
{
    t_fract *fract = (t_fract *)param;
    fract->vars.z.real = coodinates_converter_x(fract->vars.win_axis.x, fract);
    fract->vars.z.imag = coodinates_converter_y(fract->vars.win_axis.y, fract);
    while (fract->vars.iterations < fract->vars.max_iteration)
    {
        julia_formula(&fract->vars.z, fract->vars.c);
        if (sqrt_root_modulus(fract->vars.z) > 4)
            break;
        fract->vars.iterations++;
    }
    set_pixel_color(fract, fract->vars.iterations, fract->vars.z);
    fract->vars.iterations = 0;
    mlx_put_pixel_img(fract);
    //printf("%f %f\n",fract->vars.win_axis.x, fract->vars.win_axis.y);
}


// int render_julia(t_fract *fract)
// {
//     fract->vars.win_axis.x = 0;
//     while (fract->vars.win_axis.x < WIDTH)
//     {
//         fract->vars.win_axis.y = 0;
//         while (fract->vars.win_axis.y < HIGHT)
//         {
//             iterate_julia(fract);
//             mlx_put_pixel_img(fract);
//             fract->vars.win_axis.y++;
//         }
//         fract->vars.win_axis.x++;
//     }
//     mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
// 			fract->img_vars.img, 0, 0);
//     return (0);
// }

void pthread_julia(t_fract *fract)
{
    pthread_t *thread;
    int i;
    int j;
    
    thread = malloc(sizeof(pthread_t) * THREADS_AMOUNT);
    i = 0;
    j = 0;
    fract->vars.win_axis.x = 0;
    while (fract->vars.win_axis.x < WIDTH)
    {
        fract->vars.win_axis.y = 0;
        while (fract->vars.win_axis.y < HIGHT)
        {   i=0;
        
            pthread_create(&thread[i],NULL,iterate_julia,(void *)fract);
            fract->vars.win_axis.y++;
            i++;
            
            if (fract->vars.win_axis.y < HIGHT)
            {
                pthread_create(&thread[i],NULL,iterate_julia,(void *)fract);
                fract->vars.win_axis.y++;
                i++;
            }
            
            
            if (fract->vars.win_axis.y < HIGHT)
            {
                pthread_create(&thread[i],NULL,iterate_julia,(void *)fract);
                fract->vars.win_axis.y++;
                i++;
            }
            
            if (fract->vars.win_axis.y < HIGHT)
            {
                pthread_create(&thread[i],NULL,iterate_julia,(void *)fract);
                fract->vars.win_axis.y++;
                printf("%f",fract->vars.win_axis.x);
                printf("%f",fract->vars.win_axis.y);
                i++;
            }
            while(j < THREADS_AMOUNT)
            {
    	        pthread_join(&thread[j], NULL);
                j++;
            }
            j=0;
        }
        fract->vars.win_axis.x++;
    }
    
    mlx_put_image_to_window(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr,
			fract->img_vars.img, 0, 0);
}







