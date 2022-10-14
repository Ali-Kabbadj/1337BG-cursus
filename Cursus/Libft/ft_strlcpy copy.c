/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:45:43 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 22:08:35 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t i;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// int main()
// {
// 	char dst[20] = "abcdefghi";
// 	char dst1[20] = "abcdefghi";
// 	const char src[10] = "123456789";

// 	int a = ft_strlcpy(dst,src,20);
// 	int b = strlcpy(dst1,src, 20);

// 	printf("mine   : %d - %s\n",a, dst);
// 	printf("thiers : %d - %s",b, dst1);

// }
