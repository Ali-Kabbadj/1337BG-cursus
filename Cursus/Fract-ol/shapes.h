#ifndef SHAPES_H
#define SHAPES_H

#include "fractol.h"
typedef struct s_rect
{
    int x_upper_left;
    int y_upper_left;
    int width;
    int height;
    int color;
} t_rect;

int render_rect(t_data *data, t_rect rect);
void render_background(t_data *data, int color);

#endif