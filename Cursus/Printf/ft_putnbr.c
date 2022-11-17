/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:21:47 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:21:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
