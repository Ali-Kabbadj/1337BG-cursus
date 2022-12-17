#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct s_complex
{
    float real;
    float imag;
}   t_complex;

t_complex add(t_complex n1, t_complex n2);
t_complex sqrt_complex(t_complex nb);

#endif