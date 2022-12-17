#include "complex.h"


t_complex add(t_complex n1, t_complex n2)
{
    t_complex resultnb;

    resultnb.real = n1.real + n2.real;
    resultnb.imag = n1.imag + n2.imag;
    return (resultnb);
}

t_complex sqrt_complex(t_complex nb)
{
    t_complex result;
    
    result.real = nb.real * nb.real - nb.imag * nb.imag;
    result.imag = nb.imag * nb.real + nb.real * nb.imag;
    return (result);
}