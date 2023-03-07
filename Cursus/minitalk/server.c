/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:37:42 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/07 18:36:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void	default_handler(int sig, siginfo_t *si, void *data)
{
	static int	bit_number;
	static char	res;
	int			a;

	(void)data;
	if (sig == SIGUSR1)
		res = res << 1;
	else
		res = (res << 1) | 1;
	bit_number++;
	if (bit_number == CHAR_BIT)
	{
		a = write(1, &res, 1);
		if (a == -1)
		{
			kill(si->si_pid, SIGUSR2);
			usleep(500);
			exit(0);
		}
		res = 0;
		bit_number = 0;
	}
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = default_handler;
	pid = getpid();
	ft_printf("%d\n", PID);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
