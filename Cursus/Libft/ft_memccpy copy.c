/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:55 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/13 22:23:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memccpy(void *dst, const void * src, int c, size_t n)
{
    size_t i;
    unsigned char * dest;
    unsigned char * sourc;
    dest = (unsigned char *)dst;
    sourc = (unsigned char *)src;

    i = 0;
    while (i < n && *sourc)
    {
        dest[i] = sourc[i];
        if(sourc[i] == (unsigned char)c)
            return (dest + i + 1);
        i++;
    }
    return (0);
}

int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];


   printf("%s\n", ft_memccpy(dest ,src, 't',10));
   
   return(0);
}