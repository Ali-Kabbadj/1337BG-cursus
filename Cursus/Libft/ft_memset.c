/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:35:40 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/22 08:01:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
