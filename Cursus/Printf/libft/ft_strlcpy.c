/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:45:43 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 23:18:03 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

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
/*#include <stdio.h>
#include <string.h>
int main()
{
	char dst1[13] = "abcde";
	char dst2[13] = "abcde";

	const char src[] = "fghigk";

	printf("mine : %zu | %s\n", ft_strlcpy(dst1, src, 13), dst1);
	printf("original : %zu | %s", strlcpy(dst2, src, 13), dst2);


}*/
