#include "fractol.h"

int close_program(void *param)
{
    t_fractal *fract;
    fract = (t_fractal*)param;
    mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
    exit(0);
}

int handle_keypress(int keycode, void *param)
{
    t_fractal *fract;
    fract = (t_fractal*)param;
    if (keycode == 53)
        close_program (fract);
    if (keycode == 49)
    {
        //render_background(fract, 0xfffff);
        // generate_julia(fract);
        // mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.img, 0, 0);
    }
    if (keycode == 8)
        mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
    return (0);
}

// int handle_mouse_move(int button, int x, int y, void *param)
// {
//     static int i;
//     static int last_x;
//     static int last_y;

//     t_mlx_vars *mlx;
//     mlx = (t_mlx_vars*)param;
//     if (button == 4 && mlx->win_ptr != NULL)
//     {
//         if (last_x == 0)
//             last_x = 100;
//         if (last_y == 0)
//             last_y = 100;
//         render_background(&(mlx->img), 0xFFFFFF);
//         render_rect(&(mlx->img), (t_rect){0,0, last_x + i, last_y + i,0xFF00});
//         mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
//         printf("%d -%d - %d\n",x , y,button);
//         last_x += i;
//         last_y += i;
//         i++;
//     }
//     if (button == 5 && mlx->win_ptr != NULL)
//     {
//         if (last_x == 0)
//             last_x = 100;
//         if (last_y == 0)
//             last_y = 100;
//         render_background(&(mlx->img), 0xFFFFFF);
//         render_rect(&(mlx->img), (t_rect){0,0, last_x - i, last_y - i,0xFF00});
//         mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
//         printf("%d -%d - %d\n",x , y,button);
//         last_x -= i;
//         last_y -= i;
//         i++;
//     }
//     return (0);
// }