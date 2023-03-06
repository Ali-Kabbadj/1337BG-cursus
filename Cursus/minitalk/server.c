/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:42 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/06 19:59:55 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include <signal.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_bit_one(char *res)
{
    *res =  (*res << 1 ) | 1;
}

void add_bit_zero(char *res)
{
    *res = *res << 1;
}

 void default_handler(int sig , siginfo_t *si, void *data)
{
    static int bit_number;
    static int first_bytes;
    static int len;
    static char res;
    static int pause;
    static int old_pid;
    static int new_pid;
    
    (void)data;
    if (sig == SIGUSR1)
        add_bit_zero(&res);
    else if (sig == SIGUSR2)
        add_bit_one(&res);
    bit_number++;
    if (bit_number == 8)
    {
        if (first_bytes == 0)
        {
            len = res;
            first_bytes = -1;
        }
        else
        {
            ft_putchar(res);
            kill(si->si_pid, SIGUSR2);
        }
        if (res == '\n')
        {
            first_bytes = 0;
            kill(SIGUSR1,new_pid);
            old_pid = new_pid;
        }
        res = 0;
        bit_number = 0;
    }
}



int main(void)
{
    int PID;
    struct sigaction sa;
    ft_memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = default_handler;
    
    PID = getpid();
    ft_printf("%d\n",PID);
    sigaction(SIGUSR1, &sa , 0);
    sigaction(SIGUSR2, &sa , 0);
    
    while (1)
    {   
        
        pause();
    }
}

// int main(void)
// {
//     int PID;
    
//     PID = getpid();
//     ft_printf("%d\n",PID);
//     signal(SIGUSR1,default_handler);
//     signal(SIGUSR2,default_handler);
//     while (1)
//     {
//         pause();
//     }
// }   