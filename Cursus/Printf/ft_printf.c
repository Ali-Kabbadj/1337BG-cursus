/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:19:46 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:19:49 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_handle_arg_type(va_list arguments, const char arg)
{
    int printcount;

    printcount = 0;
    if (arg == 'c')
        printcount = ft_putchar(va_arg(arguments, int));
    else if (arg == 's')
        printcount = ft_putstr(va_arg(arguments, char *));
    else if (arg == 'p')
        printcount = ft_putptr(va_arg(arguments, unsigned long long));
    else if (arg == 'd' || arg == 'i')
        printcount = ft_putnbr(va_arg(arguments, int));
    else if (arg == 'u')
        printcount = ft_putunsigned(va_arg(arguments, unsigned int));
    else if (arg == 'x' || arg == 'X')
        printcount = ft_puthex(va_arg(arguments, unsigned int), arg);
    else if (arg == '%')
        printcount = ft_putpercent();
    return (printcount);
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list arguments;
    int printcount;

    i = 0;
    printcount = 0;
    va_start(arguments, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            printcount += ft_handle_arg_type(arguments, format[i + 1]);
            i++;
        }
        else
            printcount += ft_putchar(format[i]);
        i++;
    }
    va_end(arguments);
    return (printcount);
}
