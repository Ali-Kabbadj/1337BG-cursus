/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:12:30 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 22:21:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src , size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		i++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char *src = "abcdefgh";
	char *dst;
	dst = src + 1;
	memcpy(dst, src, 3);
	printf("%s",dst);
}