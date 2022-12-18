#ifndef FRACTOL_H
#define FRACTOL_H
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>


typedef struct s_mlx_vars
{
    void *mlx_ptr;
    void *win_ptr;
    t_data img;
}   t_mlx_vars;

typedef struct s_data
{
    void *img;
    char *address;
    int bits_per_pixel;
    int line_length;
    int endian; /*true or false*/
}   t_data;


void costum_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_triangle(void *img);
void draw_reverse_trainge(void *img);
int handle_keypress(int keycode,void *vars);
#endif