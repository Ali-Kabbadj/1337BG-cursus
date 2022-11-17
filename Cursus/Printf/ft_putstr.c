/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:22:45 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:22:48 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
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
