/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:57 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/18 11:25:47 by alika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;
	size_t	lentocpy;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	if (dstsize < dstlen)
		return (dstsize + srclen);
	if (dstsize < sizeof(dst))
		return (dstlen + srclen);
	lentocpy = dstsize - dstlen - 1;
	i = dstlen;
	while (j < lentocpy && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + srclen);
}
