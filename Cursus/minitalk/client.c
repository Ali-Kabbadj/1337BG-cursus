/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:39 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/07 18:38:24 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>

void	handle_server_notif(int sig)
{
	static int	bytes_cnt;
	static int	bit;

	if (sig == SIGUSR1)
	{
		bit++;
		ft_printf("Server has recieved %d bit", bit);
		ft_printf(" of byte No %d.\n", bytes_cnt);
		if (bit == 8)
		{
			bytes_cnt++;
			bit = 0;
			ft_printf("\n\n");
		}
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Something When wrong on the server's side");
		exit(0);
	}
}

static int	ft_check_pid(char *PID)
{
	int	i;

	i = 0;
	while (PID[i])
	{
		if (ft_isdigit(PID[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	send_bits(int c, int i, int PID)
{
	if (i < 7)
	{
		i++;
		send_bits(c, i, PID);
		if ((c & (1 << i)) == 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(22500);
	}
}

void	check_args(int ac, char **av)
{
	if (ac < 3)
	{
		ft_printf("Wrong arg number");
		exit(0);
	}
	if (ft_check_pid(av[1]) == -1)
	{
		ft_printf("Wrong PID format");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	check_args(ac, av);
	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, handle_server_notif);
	signal(SIGUSR2, handle_server_notif);
	while (av[2][i])
	{
		send_bits(av[2][i], -1, pid);
		i++;
	}
	send_bits('\n', -1, pid);
	return (0);
}
