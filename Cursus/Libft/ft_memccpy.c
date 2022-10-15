/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:55 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/13 22:23:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	i = 0;
	while (i < n && *sourc)
	{
		dest[i] = sourc[i];
		if (sourc[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
