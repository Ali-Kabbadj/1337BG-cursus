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
#include <stdio.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int dstlen;
	int srclen;
	int i;
	i = 0;
	
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if(dstsize == 0)
		return (srclen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i]= '\0';
	return (srclen);
}

int main()
{

	char dst[0];
	char *r = "123456";
	printf("%s\n",r);
	r = dst + 1; 
	char *src = "hellohsyjnhysjuythsstrvgtsrkimdrytrgvsyh";
	printf("%zu\n%s\n",ft_strlcpy(dst,src,4),dst); 
	printf("%s\n",r);
}

