/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:16:48 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/09 21:43:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;
	
	i = 0;
	sign = 1;
	res = 0;
	while(str[i] && str[i] <= 32)
		i++;
	if(str[i] == '-'){
		sign = -1;
		i++;
	}
	else if(str[i] == '+'){
		sign = 1;
		i++;
	}
	while(str[i] && str[i] >= '0' && str[i] <= '9'){
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return res * sign;
}
