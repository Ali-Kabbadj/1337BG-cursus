/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:39 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/05 17:36:32 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
#include <stdio.h>

static int ft_check_pid(char *PID)
{
    int i;

    i = 0;
    while (PID[i])
    {
        if (ft_isdigit(PID[i]) == 0)
            return (-1);
        i++;
    }
    return (0);
}

void send_bits(int c, int i, int PID)
{
    if (i > 0)
    {
        send_bits(c / 2, i - 1, PID);
        if (c % 2 == 0)
            kill(PID, SIGUSR1);
        else
            kill(PID, SIGUSR2);
        printf("%d",c % 2);
        usleep(300); 
    }
    
}


void check_args(int ac, char **av)
{
    if (ac < 3)
    {
        ft_printf("Wrong arg number");
        exit(0);
    } 
    if (ft_check_pid(av[1]) == - 1)
    {
        ft_printf("Wrong PID format");
        exit(0);
    }
}

int main(int ac, char **av)
{
    int PID;
    int i;
    int len;

    
    check_args(ac, av);
    i = 0;
    len = ft_strlen(av[2]);
    PID = ft_atoi(av[1]);
    
    
    
    send_bits(len, 8, PID);
    
    while (av[2][i])
    {
        printf("\n");
        send_bits(av[2][i], 8, PID);
        i++;
    }
    send_bits('\n', 8, PID);
}