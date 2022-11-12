#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"
#include <unistd.h>

int ft_printf(const char *format, ...);
int ft_putunsigned(unsigned int u_nb);
int ft_puthex(unsigned int nb_hex, const char argformat);
int ft_putptr(unsigned long long ptr);
int ft_putpercent(void);
int ft_putnbr(int nb);
int ft_putstr(char *s);
int ft_putchar(int c);
#endif
