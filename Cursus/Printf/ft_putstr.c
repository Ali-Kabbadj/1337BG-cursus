#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}