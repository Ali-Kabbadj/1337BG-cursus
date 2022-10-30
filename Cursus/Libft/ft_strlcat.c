/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:57 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/30 13:01:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	j;
	size_t	reslen;

	j = 0;
	reslen = ft_strlen(src) + ft_strlen(dst);
	dstlen = ft_strlen(dst);
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize > dstlen)
		reslen = ft_strlen(src) + dstlen;
	else
		reslen = ft_strlen(src) + dstsize;
	while (dstlen < dstsize - 1 && src[j])
		dst[dstlen++] = src[j++];
	dst[dstlen] = '\0';
	return (reslen);
}
