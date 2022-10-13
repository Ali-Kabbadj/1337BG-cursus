/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:48:50 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:13:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t slen;

	slen = (size_t)ft_strlen((const char *)s);
	if (c == '\0')
		return ((void *)s + slen);
	while (n + 1 > -1)
	{
		if (*((unsigned char *)s + n) == (unsigned char)c)
			return (((void *)s + n));
		n--;
	}
	return (0);
}
