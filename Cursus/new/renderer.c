#include "fractol.h"

void put_pixel(t_data *canva, int x, int y, int color)
{
    char *dest;

    dest = canva->adresse + (y * canva->line_length + x * (canva->bpp / 8));
    *(unsigned int *)dest = color;
}

void render_background(t_fractal *fract, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fract->win_hight)
    {
        x = 0;
        while (x < fract->win_width)
        {
            put_pixel(&(fract->canva), x, y, color);
            //printf("color:%d\n y: %d\n x: %d",color,y, x);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->canva.img, 0, 0);
}