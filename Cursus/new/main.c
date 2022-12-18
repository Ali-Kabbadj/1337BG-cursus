#include "fractol.h"
#include "sets.h"
int main(void)
{
    t_fractal *fract;

    fract = malloc(sizeof(t_fractal));
    if (init_fractal(fract, WIN_WIDTH, WIN_HIGHT, WIN_TITLE))
    {
        free (fract);
        return (1);
    }
    init_hooks(fract);
    init_img(fract);
    render_background(fract, 0xFFFFFF);
    t_set *set;
    set = malloc(sizeof(t_set));
    set->real = 0;
    set->imag =0;

    set->creal = 0.687;
    set->cimag = 0.312;

    set->xmax = 2;
    set->xmin = -2;
    
    set->ymax = 2;
    set->ymin = -2;
    render_set(set,fract);
    mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->canva.img, 0, 0);
    mlx_loop(fract->mlx_ptr);
    return (0);
}