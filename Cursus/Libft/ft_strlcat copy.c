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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;
	size_t	lentocpy;

	i = 0;
	j = 0;
	dstlen = 0;
	srclen = 0;
	if (!dstsize)
		return (dstsize);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (dstsize < dstlen)
		return (dstsize + srclen);
	lentocpy = dstsize - dstlen - 1;
	while (j < lentocpy)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

// int main ()
// {


// 	char dstmine[10] = "something";

// 	//size_t a = strlcat(dstmine, (void*)0, 50);
// 	size_t b = ft_strlcat(dstmine, (void*)0, 2);

// 	//printf("thiers : \n return : %zu \n array : %s\n",a,dstmine);
// 	printf("Mine : \n return : %zu \n array : %s\n",b,dstmine);
// }
