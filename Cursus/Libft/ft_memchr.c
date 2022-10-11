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

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	size_t	slen;
	
	i = 0;
	slen = ft_strlen((char *)s);
	if (n == slen && c == '\0')
		return ((void *)s + slen);
	while (*((unsigned char*)s + i) && i < n)
	{
		if(*((unsigned char*)s + i) == (unsigned char)c)
			return (((void *)s + i));
		i++;
	}
	return (0);
}
