/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:59:18 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:19:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && src1[i] == src2[i] )
		i++;
	return (src1[i] - src2[i]);
}

// int main()
// {
// 	char *s1 = "\xff\xaa\xde\x12";
// 	char *s2 = "\xff\xaa\xde\x12MACOSAAAAA";
// 	size_t size = 4;
// 	printf("thiers : %d \n", memcmp(s1, s2, size));
// 	printf("mine   : %d",ft_memcmp(s1, s2, size));
// }
