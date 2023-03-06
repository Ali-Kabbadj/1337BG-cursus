/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:39 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/06 19:50:44 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
#include <stdio.h>

int pause_pros;

void handle_server_notif(int sig)
{
    static int bytes_cnt;
    if(sig == SIGUSR2)
    {
        (void)sig;
        bytes_cnt++;
        ft_printf("server has recieved %d byte(s)\n",bytes_cnt);
    }
    else if (sig == SIGUSR1)
        pause_pros = !pause_pros;
}

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
    if (i < 7)
    {
        i++;
        send_bits(c ,i, PID);
        if ((c & (1 << i)) == 0)
            kill(PID, SIGUSR1);
        else    
            kill(PID, SIGUSR2);
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
    
    signal(SIGUSR2, handle_server_notif);
    signal(SIGUSR1, handle_server_notif);
    check_args(ac, av);
    i = 0;
    PID = ft_atoi(av[1]); 
    len = ft_strlen(av[2]);
    send_bits(len, -1, PID);
    while (av[2][i])
    {
        if (!pause_pros)
        {
            send_bits(av[2][i], -1, PID);
            i++;
        }else
            usleep(300);
    }
    send_bits('\n', -1, PID);
}