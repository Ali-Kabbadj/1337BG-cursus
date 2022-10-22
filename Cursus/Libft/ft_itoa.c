/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:30 by alika             #+#    #+#             */
/*   Updated: 2022/10/22 08:30:03 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_estimate_array_size(long n)
{
	size_t	estimation;

	estimation = 0;
	if (n < 0)
	{
		estimation = 1;
		n *= -1;
	}
	while (n >= 1)
	{
		estimation++;
		n = n / 10;
	}
	return (estimation);
}

static char	*ft_create_array(char *res, int nbr, int nbrlen, int isneg)
{
	if (nbr != 0)
		res = malloc((nbrlen + 1) * sizeof(char));
	else
		return (ft_strdup("0"));
	if (!res)
		return (0);
	res[nbrlen--] = '\0';
	while (nbrlen)
	{
		res[nbrlen--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (isneg)
		res[0] = '-';
	else
		res[0] = nbr % 10 + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		nlen;
	int		isneg;

	res = NULL;
	nlen = ft_estimate_array_size(n);
	isneg = 0;
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		isneg = 1;
		n *= -1;
	}
	res = ft_create_array(res, n, nlen, isneg);
	return (res);
}
