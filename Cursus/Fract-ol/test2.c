#include "fractol.h"
#include <mlx.h>


int initialize_window(t_mlx_vars *mlx, int width, int hight , char *title)
{
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, hight, title);
    if (mlx->win_ptr == NULL)
        return (1);
    return (0)
}

int initialize_mlx(t_mlx_vars *mlx)
{
    mlx->mlx_ptr = mlx_init();
    if (mlx->mlx_ptr == NULL)
        return (1);
    if (initialize_window(mlx, 1920, 1080, "fract-ol"))
        return (1);
    return (0);
}



int main(void)
{
    t_mlx_vars *mlx;

    if (initialize_mlx(mlx))
        return (1);

    return (0);
}