#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int ft_putnbr(int nb)
{
    int len;
    char *res;

    len = 0;
    res = ft_itoa(nb);
    len = ft_putstr(res);
    free(res);
    return (len);
}