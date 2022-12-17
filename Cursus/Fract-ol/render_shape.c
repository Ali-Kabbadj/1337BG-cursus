#include "shapes.h"
#include "fractol.h"

int render_rect(t_data *data, t_rect rect)
{
    int i;
    int j;

    i = rect.y_upper_left;
    while (i < rect.y_upper_left + rect.height)
    {
        j = rect.x_upper_left;
        while (j < rect.x_upper_left + rect.width)
        {
            costum_mlx_pixel_put(data,j++, i, rect.color);
        }
        i++;
    }
    return (0);
}