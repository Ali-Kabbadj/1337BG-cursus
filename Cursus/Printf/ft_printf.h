/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:20:07 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:20:10 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_putunsigned(unsigned int u_nb);
int ft_puthex(unsigned int nb_hex, const char argformat);
int ft_putptr(unsigned long long ptr);
int ft_putpercent(void);
int ft_putnbr(int nb);
int ft_putstr(char *s);
int ft_putchar(int c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
#endif
