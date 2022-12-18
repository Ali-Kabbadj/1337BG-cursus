#include "sets.h"


void handle_signe(float x, float y , t_set *set)
{
    if (x >= WIN_WIDTH / 2 && y >= WIN_HIGHT / 2)
        set->imag = (set->imag * -1);
    else if (x < WIN_WIDTH / 2 && y > WIN_HIGHT / 2)
    {
        set->real =(set->real * -1) ;
        set->imag =( set->imag * -1);
    }
    else if (x < WIN_WIDTH / 2 && y < WIN_HIGHT / 2)
    {
        set->real = set->real * - 1;
    }
}


void convert_coordenates(float x, float y , t_set *set)
{
    if (x > WIN_WIDTH / 2 && y > WIN_HIGHT / 2)
    {
        set->real = (x - (WIN_WIDTH / 2)) / (WIN_WIDTH / 2) * 2;
        set->imag = (y - (WIN_HIGHT / 2)) / (WIN_HIGHT / 2) * 2;
    }
    if (x < WIN_WIDTH / 2 && y > WIN_HIGHT / 2)
    {
        set->real = ((WIN_WIDTH / 2) - x) / (WIN_WIDTH / 2) * 2;
        set->imag = (y - (WIN_HIGHT / 2)) / (WIN_HIGHT / 2) * 2;
    }
    else if (x < WIN_WIDTH / 2 && y < WIN_HIGHT / 2)
    {
        set->real = ((WIN_WIDTH / 2) - x) / (WIN_WIDTH / 2) * 2;
        set->imag = ((WIN_HIGHT / 2) - y) / (WIN_HIGHT / 2) * 2;
    }
    else
    {
        set->real = (x - (WIN_WIDTH / 2)) / (WIN_WIDTH / 2) * 2;
        set->imag = ((WIN_HIGHT / 2) - y) / (WIN_HIGHT / 2) * 2;
    }
    handle_signe(x , y, set);
}

double calculate_distance_from_origine(t_set set)
{
    return (set.real * set.real + set.imag * set.imag);
}

// void scale_coordinates(t_set *set,t_fractal fract, int x, int y)
// {
//     set->real = 0.5 * (x - fract.win_width / 2) / (0.7 * fract.win_hight);
//     set->imag = (y - fract.win_width / 2) / (0.7 * fract.win_hight);
// }

t_bordercheck check_border(int x ,int y , t_set *set)
{
    float tmpre;
    float tmpmg;
    int nbeter = 0;
    float distance_origin = 0;
    t_bordercheck rest;

    tmpre = 0;
    tmpmg = 0;
    convert_coordenates(x,y,set);
    //scale_coordinates(set, fract, x, y);
    tmpre = set->real;
    tmpmg = set->imag;
    while (nbeter < 100 && distance_origin <= 4)
    {
        
        set->real = (set->real * set->real) - (set->imag * set->imag);
        set->imag = 2 * tmpre * tmpmg;
        set->real = set->real - set->creal;
        set->imag = set->imag - set->cimag;
        distance_origin = calculate_distance_from_origine(*set);
        nbeter++;
        //printf("%f\n",distance_origin);
        tmpre = set->real;
        tmpmg = set->imag;
    }
    rest.distance = distance_origin;
    rest.nbeter = nbeter;
    return (rest); 
}

void render_set(t_set *set , t_fractal *fract)
{
    int x;
    int y;
    t_bordercheck border;

    x = 0;
    y = 0;
    while (y < fract->win_hight)
    {
        x = 0;
        while (x < fract->win_hight)
        {
            border = check_border(x, y, set);
            if (border.nbeter > 10 && border.distance <= 4)
                put_pixel(&(fract->canva), x, y, 0x000000);
            x++;
        }
        y++;
    }
    
}

/* escape conditions -------------------------------*/
/* if either the real of imaginat part is > 2*/
/*computing distence from origin using Pythagorean theorem (ei determine the modulus of the complex number)*/
/* if this value exeeds 2*/
/*or equaly if sum of the squares of real and imag parts exceds 4*/
/*another way is to use Buddhabrot*/

/*coloring ---------------------*/
/* the color represents how quicly the values reached the escape point*/
/*back : points that failed to escape before the iteration limit*/
/**/