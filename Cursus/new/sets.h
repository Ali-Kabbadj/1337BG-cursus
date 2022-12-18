#ifndef SETS_H
#define SETS_H
#include "fractol.h"

typedef struct s_bordercheck
{
    float distance;
    int nbeter;
} t_bordercheck;

typedef struct  s_set
{
    int id;
    char *name;
    int min_value;
    int max_value;
    float real;
    float imag;
    float creal;
    float cimag;
     float xmin;
    float xmax;
    float ymin;
    float ymax;
} t_set;

double calculate_distance_from_origine(t_set set);
void scale_coordinates(t_set *set,t_fractal fract, int x, int y);
t_bordercheck check_border(int x ,int y  , t_set *set);
void render_set(t_set *set , t_fractal *fract);

#endif