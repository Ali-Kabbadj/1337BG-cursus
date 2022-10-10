/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:57 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 22:09:21 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t dstlen;
	size_t srclen;
	size_t lentocpy;
	
	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if(!src[0])
		return (dstsize);
	if(dstsize < dstlen)
		return(dstlen + dstsize);
	lentocpy = dstsize - dstlen - 1;
	i = dstlen;
	while(src[j] && j < lentocpy)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

/*int main ()
{
	char dstmine[50] = "";
	char dstthier[50] = "";

	char src[6] =  "abcd";

	size_t a = strlcat(dstthier, src, 50);
	size_t b = ft_strlcat(dstmine, src, 50);

	printf("thiers : \n return : %zu \n array : %s\n",a,dstthier);
	printf("Mine : \n return : %zu \n array : %s\n",b,dstmine);
}*/
