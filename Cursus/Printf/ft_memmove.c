/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:16:10 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:19:25 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	write_from_start(unsigned char *dest,
			unsigned char *source, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
}

static void	write_from_end(unsigned char *dest,
			unsigned char *source, size_t len)
{
	while (len > 0)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*dest;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (dst < src)
		write_from_start(dest, source, len);
	else
		write_from_end(dest, source, len);
	return (dst);
}
