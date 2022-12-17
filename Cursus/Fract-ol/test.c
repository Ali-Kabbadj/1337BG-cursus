#include "shapes.h"
#include "fractol.h"
#include "complex.h"

typedef struct s_mlx_vars
{
    void *mlx_ptr;
    void *win_ptr;
    t_data img;
}   t_mlx_vars;

// void draw_triangle(void *img)
// {
//     int x = 600;
//     int y = 600;
//     while (x < 1200)
//     {
//         costum_mlx_pixel_put(img, x, y, 0x00FF0000);
//         x++;
//     }
//     x = 600;
//     while (x <= 900)
//     {
//         costum_mlx_pixel_put(img, x , y, 0x00FF0000);
//         x++;
//         y--;
//     }
//     x = 1200;
//     y = 600;
//     while (x >= 900)
//     {
//         costum_mlx_pixel_put(img, x , y, 0x00FF0000);
//         x--;
//         y--;
//     }
// }
// void draw_reverse_trainge(void *img)
// {
//     int x = 460;
//     int y = 40;
//     double tmpy = 0;
//     while (x < 1461)
//     {
//         costum_mlx_pixel_put(img, x, y, 0x00FF0000);
//         x++;
//     }
//     x = 460;
//     while ( x <= 960)
//     {
//         tmpy = 3.65 *pow(1.0052189509, x);
//         y = tmpy;
//         costum_mlx_pixel_put(img, x , y , 0x00FF0000);
//         x++;
//     }
// }

/* (0 , 0)        (960 , 0)      (1920 , 0) */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* (0 , 540)     (960 ,540)     (1920,540)| */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* |                                      | */
/* (0 , 1080)   (960, 1080)   (1920 , 1080) */


t_complex get_next_nb(t_complex nb, int x, int y)
{
    nb.real = 1.5 * (x - 1920 / 2) / (0.5 *  1920);
    nb.imag = (y - 1080 / 2) / (0.5 * 1080);
    return (nb);
}

double calculate_distance_from_origine(t_complex nb)
{
    return (nb.real * nb.real + nb.imag * nb.imag);
}

int recursive_check(int x, int y)
{
    t_complex newnb;
    t_complex oldnb;
    float d;
    int eterations;

    newnb.real = x;
    newnb.imag = y;
    oldnb.real = x;
    oldnb.imag = y;
    d = 0;
    //d = calculate_distance_from_origine(newnb);
    eterations = 0;
    while (d <= 4 && eterations < 250)
    {
        newnb = get_next_nb(newnb , x, y);
        oldnb = newnb;
        newnb.real = oldnb.real * oldnb.real - oldnb.imag *oldnb.imag;
        newnb.imag = 2 * oldnb.real * oldnb.imag;
        newnb = add(newnb , oldnb);
        newnb = add(newnb , (t_complex){0, 0.65});
        d = calculate_distance_from_origine(newnb);
        eterations++;
    }
    return (eterations);
}

void generate_julia(t_mlx_vars *mlx)
{
    int x;
    int y;
    int eterations;

    x = 0;
    y = 0;
    eterations = 0;
    while (y <= 1080)
    {
        x = 0;
        while (x <= 1920)
        {
            eterations = recursive_check(x, y);
            if (eterations && eterations > 50 && eterations < 100)
                costum_mlx_pixel_put(&(mlx->img), x, y, 0x52FF00);
            if (eterations && eterations > 100 && eterations < 150)
                costum_mlx_pixel_put(&(mlx->img), x, y, 0x0700FF);
            if (eterations && eterations > 150 && eterations < 200)
                costum_mlx_pixel_put(&(mlx->img), x, y, 0x00FFAC);
            if (eterations && eterations > 200 && eterations < 250)
                costum_mlx_pixel_put(&(mlx->img), x, y, 0xFC00FF);
            x++;
        }
        y++;
    }
}

int handle_keypress(int keycode,void *vars)
{
    t_mlx_vars *mlx;
    mlx = (t_mlx_vars*)vars;
    if (keycode == 53)
    {
        mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
        exit(0);
    }
    if (keycode == 49)
    {
        render_background(&(mlx->img), 0xFFFFFF);
        // render_rect(&(mlx->img), (t_rect){1920 - 100, 1080 - 100, 100, 100 ,0x00FF0000});
        // render_rect(&(mlx->img), (t_rect){0,0, 100, 100 ,0xFF00});
        generate_julia(mlx);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
    }
    if (keycode == 8)
    {
        mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    }
    return (0);
}


int initialize_mlx(t_mlx_vars *mlx)
{
    mlx->mlx_ptr = mlx_init();
    if (mlx->mlx_ptr == NULL)
    {
        printf("Error mlx ptr\n");
        return (1);
    }
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Hello World!");
    if (mlx->win_ptr == NULL)
    {
        printf("Error mlx_win ptr");
        free(mlx->win_ptr);
        return(1);
    }
    return (0);
}

void initialize_img(t_mlx_vars *mlx)
{
    mlx->img.img = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
    mlx->img.address = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length,&mlx->img.endian);
}
int close_program(void *param)
{
    t_mlx_vars *mlx;
    mlx = (t_mlx_vars*)param;
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);
}

int handle_mouse_move(int button, int x, int y, void *param)
{
    static int i;
    static int last_x;
    static int last_y;

    t_mlx_vars *mlx;
    mlx = (t_mlx_vars*)param;
    if (button == 4 && mlx->win_ptr != NULL)
    {
        if (last_x == 0)
            last_x = 100;
        if (last_y == 0)
            last_y = 100;
        render_background(&(mlx->img), 0xFFFFFF);
        render_rect(&(mlx->img), (t_rect){0,0, last_x + i, last_y + i,0xFF00});
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
        printf("%d -%d - %d\n",x , y,button);
        last_x += i;
        last_y += i;
        i++;
    }
    if (button == 5 && mlx->win_ptr != NULL)
    {
        if (last_x == 0)
            last_x = 100;
        if (last_y == 0)
            last_y = 100;
        render_background(&(mlx->img), 0xFFFFFF);
        render_rect(&(mlx->img), (t_rect){0,0, last_x - i, last_y - i,0xFF00});
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
        printf("%d -%d - %d\n",x , y,button);
        last_x -= i;
        last_y -= i;
        i++;
    }
    return (0);
}

void initialize_hooks(t_mlx_vars *mlx)
{
    mlx_key_hook(mlx->win_ptr, handle_keypress, mlx);
    mlx_hook(mlx->win_ptr, 17, 1L<<17, close_program, mlx);
}



int main(void)
{
    t_mlx_vars *mlx;

    int error;
    mlx = malloc(sizeof(t_mlx_vars));
    error = initialize_mlx(mlx);
    if (error)
        return (1);
    initialize_img(mlx);    
    initialize_hooks(mlx);
    mlx_mouse_hook(mlx->win_ptr, handle_mouse_move, mlx);

    mlx_loop(mlx->mlx_ptr);
    return (0);
}


