#include "fractol.h"
#include "shapes.h"


void costum_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void render_background(t_data *data, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while (y <= 1080)
    {
        x = 0;
        while (x <= 1920)
        {
            costum_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
    
}