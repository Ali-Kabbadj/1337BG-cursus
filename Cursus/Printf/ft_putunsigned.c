#include "ft_printf.h"
#include <stdlib.h>

int ft_estimate_nb_len(unsigned int nb)
{
    int len;

    len = 0;
    while (nb != 0)
    {
        len++;
        nb = nb / 10;
    }
    return (len);
}

char *ft_itoa_unsigned(unsigned int nb)
{
    char *res;
    int len;

    len = ft_estimate_nb_len(nb);
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
        return (0);
    res[len] = '\0';
    while (nb != 0)
    {
        res[len - 1] = nb % 10 + '0';
        nb = nb / 10;
        len--;
    }
    return (res);
}

int ft_putunsigned(unsigned int nb)
{
    int printcount;
    char *res;

    printcount = 0;
    if (nb == 0)
        printcount += write(1, "0", 1);
    else
    {
        res = ft_itoa_unsigned(nb);
        printcount += ft_putstr(res);
        free(res);
    }
    return (printcount);
}