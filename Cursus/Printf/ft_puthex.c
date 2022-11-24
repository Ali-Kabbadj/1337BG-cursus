/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:21:27 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:21:31 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_estimate_hex_len(unsigned int nb_hex)
{
	int	len;

	len = 0;
	while (nb_hex != 0)
	{
		len++;
		nb_hex = nb_hex / 16;
	}
	return (len);
}

static void	ft_handle_hex_case(unsigned int nb_hex, const char argformat)
{
	if (nb_hex >= 16)
	{
		ft_handle_hex_case(nb_hex / 16, argformat);
		ft_handle_hex_case(nb_hex % 16, argformat);
	}
	else
	{
		if (nb_hex <= 9)
			ft_putchar_fd((nb_hex + '0'), 1);
		else
		{
			if (argformat == 'x')
				ft_putchar_fd((nb_hex - 10 + 'a'), 1);
			if (argformat == 'X')
				ft_putchar_fd((nb_hex - 10 + 'A'), 1);
		}
	}
}

int	ft_puthex(unsigned int nb_hex, const char argformat)
{
	if (nb_hex == 0)
		return (write(1, "0", 1));
	else
		ft_handle_hex_case(nb_hex, argformat);
	return (ft_estimate_hex_len(nb_hex));
}
