/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:42 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/05 17:20:39 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include <signal.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char res;

void add_bit_one()
{
    res =  (res << 1 ) + 1;
    printf("1");
}

void add_bit_zero()
{
    res = res << 1;
    printf("0");
}

 void default_handler(int sig)
{
    static int bit_number;
    static int first_bytes;
    static int len;
    static char *s;
    static int i;
    char *b;
    
    if (sig == SIGUSR1)
        add_bit_zero();
    else if (sig == SIGUSR2)
        add_bit_one();
    bit_number++;
    
    
    
    if (bit_number == 8)
    {
        printf("\n");
        if (first_bytes == 0)
        {
            len = res;
            s = malloc(sizeof(char) * len + 1);
            first_bytes = -1;
        }
        else
        {
            b = malloc(sizeof(char) * 2);
            b[0] =  res;
            b[1] = '\0';
            s = ft_strjoin(s, b);
            ft_bzero(b, 2);
            free(b);
            i++;
        }
        res = 0;
        bit_number = 0;
        if (i - 1 == len)
        {
            printf("%s",s);
            first_bytes = 0;
            i = 0;
            free(s);
        }
    }
    
}




/*
    0      its one byte
    110    a char of two bytes
    1110   a char of three bytes
    11110  a char of four bytes
*/

int main(void)
{
    int PID;
    
    PID = getpid();
    ft_printf("%d\n",PID);
    signal(SIGUSR1,default_handler);
    signal(SIGUSR2,default_handler);
    while (1)
    {
        pause();
    }
    
}


   