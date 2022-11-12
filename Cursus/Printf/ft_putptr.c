
#include "ft_printf.h"
#include "./libft/libft.h"

int ft_estimate_ptrlen(uintptr_t ptr_nb)
{
    int len;

    len = 0;
    while (ptr_nb!= 0)
    {
        len++;
        ptr_nb = ptr_nb / 16;
    }
    return (len);
}

void ft_recursive_putptr(uintptr_t ptr_nb)
{
    if (ptr_nb >= 16)
    {
        ft_recursive_putptr(ptr_nb / 16);
        ft_recursive_putptr(ptr_nb % 16);
    }
    else
    {
        if (ptr_nb <= 9)
            ft_putchar_fd((ptr_nb + '0'), 1);
        else
            ft_putchar_fd((ptr_nb - 10 + 'a'), 1);
    }
}

int ft_putptr(unsigned long long ptr)
{
    int printcount;

    printcount = 0;
    printcount += write(1, "0x", 2);
    if (ptr == 0)
        printcount += write(1, "0", 1);
    else
    {
        ft_recursive_putptr(ptr);
        printcount += ft_estimate_ptrlen(ptr);
    }
    return (printcount);
}