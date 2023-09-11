/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:23:34 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:23:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	*ft_memset(void *b, int c, int len)
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

static void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, '\0', n);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	res = malloc(slen * sizeof(char));
	if (!res)
		return (0);
	ft_bzero(res, slen);
	return ((char *)ft_memmove(res, s1, slen));
}
